#include "Timer.hpp"






#define STD_PERIOD	1000



namespace tirtos{

TIRTOS_OBJECT_CONSTRUCT(CTimer)


Void CTimer::handler(UArg a){
	(*FORCE_CAST(TFastFunctor*, a))();
}




CTimer::CTimer(TFastFunctor functor, UInt32 period, bool autostart){
	Clock_Params_init(&params);
	this->functor = functor;
	params.arg = (UArg)&this->functor;
	params.startFlag = autostart;
	params.period = period;

	if(period == 0)
		period = STD_PERIOD;

	handle = Clock_create(&handler, period, &params, &errorBlock()->Handle());
	_inc_object();
}






CTimer::~CTimer(){
	if(handle == NULL)
		return;
	Clock_delete(&handle);
	_dec_object();
}


void CTimer::setPeriod(UInt32 value){
	Clock_setPeriod(handle, value);
}


UInt32 CTimer::Period(){
	return Clock_getPeriod(handle);
}



void CTimer::start(){
	Clock_start(handle);
}


void CTimer::stop(){
	Clock_stop(handle);
}



};
