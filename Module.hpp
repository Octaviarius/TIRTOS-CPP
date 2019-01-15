#pragma once


#include <useful_header.h>
#include <stdio.h>


#define TIRTOS_MODULE_NAME_LENGTH		32




class CModule {
public:

	enum Workstate{
		WorkstateInnactive = 0,		//!< Innactive state, object not working
		WorkstateActive,			//!< Active state, normal working object
		WorkstatePassive,			//!< Passive state ??? I haven't created sense
		WorkstateSuspended,			//!< Object working suspended
		WorkstateUserStateBegin = 16
	};


	enum Error{
		ErrorSuccess = 0,				//!< Success operation
		ErrorInitAlreadySet = -1,		//!< Init state already set, but previous access
		ErrorNotInitialized = -2,		//!< Object not initialized
		ErrorWorkstateAlreadySet = -3,	//!< Workstate is same
		ErrorWorkstateUnhandled = -4,	//!< Workstate isn't handled
		ErrorUndef = -255,				//!< Undef error code
		ErrorUserError = INT_MIN,		//!< User error code
	};

private:
	char name[TIRTOS_MODULE_NAME_LENGTH];	//!< Module name
	long last_error;		//!< Last error info
	Workstate work_state;	//!< Current Workstate
	bool is_init;			//!< Flag indicate what object is initialized
protected:
	//! Get last error, and value clear
	inline void setLastError(long err)				{last_error = err;}

	//! Init function handler of childrens
	virtual long _init()							{return ErrorSuccess;}
	//! Deinit function handler of childrens
	virtual long _deinit()							{return ErrorSuccess;}
	//! Init function handler of childrens
	virtual long _reinit()							{_deinit(); return _init();}
	//! Update function handler of childrens
	virtual long _update()							{return ErrorSuccess;}
	//! Reset function handler of childrens
	virtual long _reset()							{return ErrorSuccess;}
	//! setWorstate function handler of childrens
	virtual long _setWorkstate(Workstate state)	{return ErrorSuccess;}

public:

	//! Constructor
	CModule(const char* name = "") {
		strcpy(this->name, name);
		is_init = false;
		work_state = WorkstateInnactive;
		last_error = 0;
		#if defined(_DEBUG)
		std::printf("Module \"%s\" constructor: success\n", this->name);
		#endif
	}

	//! Destructor
	virtual ~CModule() {
		if(is_init == false)
			return;
		_setWorkstate(WorkstateInnactive);
		_deinit();
		#if defined(_DEBUG)
		std::printf("Module \"%s\" destructor: success\n", name);
		#endif
	}

	//! Init function. Basic of childrens. Handling state, initializating values, creating objects, etc...
	inline long init(){
		#if defined(_DEBUG)
		std::printf("Module \"%s\" init: start\n", name);
		#endif
		if(is_init == true){
			#if defined(_DEBUG)
			std::printf("Module \"%s\" init: already inited!\n", name);
			#endif
			return last_error = ErrorInitAlreadySet;
		}
		last_error = _init();
		if(last_error == ErrorSuccess){
			is_init = true;
			#if defined(_DEBUG)
			std::printf("Module \"%s\" init: success\n", name);
			#endif
		}else{
			#if defined(_DEBUG)
			std::printf("Module \"%s\" init: error #%i\n", name, last_error);
			#endif
		}
		return last_error;
	}


	//! Deinit function. Basic of childrens. Handling state, deinitializating values, destruct objects, etc...
	inline long deinit(){
		#if defined(_DEBUG)
		std::printf("Module \"%s\" deinit: start\n", name);
		#endif
		if(is_init == false){
			return last_error = ErrorInitAlreadySet;
			#if defined(_DEBUG)
			std::printf("Module \"%s\" deinit: not inited!\n", name);
			#endif
		}if(work_state != WorkstateInnactive){
			#if defined(_DEBUG)
			std::printf("Module \"%s\" deinit: set innactive state\n", name);
			#endif
			_setWorkstate(WorkstateInnactive);
		}
		last_error = _deinit();
		if(last_error == ErrorSuccess){
			is_init = false;
			#if defined(_DEBUG)
			std::printf("Module \"%s\" deinit: success \n", name);
			#endif
		}else{
			#if defined(_DEBUG)
			std::printf("Module \"%s\" deinit: error #%i\n", name, last_error);
			#endif
		}
		return last_error;
	}


	inline long reinit(){
		return _reinit();
	}

	//! Update state handler
	long update(){
		if(is_init == false){
			last_error = ErrorNotInitialized;
			#if defined(_DEBUG)
			std::printf("Module \"%s\" update: error #%i\n", name, last_error);
			#endif
		}else{
			last_error = _update();
		}
		return last_error;
	};

	//! Reset state handler
	long reset(){
		if(is_init == false)
			return last_error = ErrorNotInitialized;
		return last_error = _reset();
	}

	//! Change inner state handler
	long setWorkstate(Workstate state){
		if(is_init == false){
			#if defined(_DEBUG)
			std::printf("Module \"%s\" set state: not inited!\n", name);
			#endif
			return last_error = ErrorNotInitialized;
		}if(work_state == state){
			return last_error = ErrorWorkstateAlreadySet;
		}else{
			last_error = _setWorkstate(state);
		}
		if(last_error == ErrorSuccess)
			work_state = state;
		return last_error;
	}


	//! Get current state object
	inline Workstate workstate()	{return work_state;}
	//! Indicates that object initialized
	inline bool isInit()			{return is_init;}
	//! Get last error, and reset value
	inline long lastError()			{return last_error;}

	inline const char* moduleName() const {return name;}

};




