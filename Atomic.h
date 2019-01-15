#pragma once

#include <stdint.h>





namespace tirtos{


/*!
 * @brief Atomic control unit. Code between lock/unlock doing atomic
 *
 */
class CAtomic{
private:
	uint16_t key;
	bool locked : 1;
public:

	CAtomic()						{locked = false;}
	//! Constructor with autostart
	CAtomic(bool is_lock)			{locked = false; if(is_lock) this->lock();}
	//! Destuctor
	~CAtomic()						{ unlock(); }

	//! Start atomic block
	void lock();
	//! Stop atomic block
	void unlock();

	//! Atomic assign value to variable
	template<class T>
	static void assign(T &variable, const T &value);

	//! Atomic swap two variables
	template<class T>
	static void swap(T &variable1, T &variable2);

	//! Atomic get value
	template<class T>
	static T getVal(const T &variable);

	template<class T>
	T call(T func);
};






template<class T>
void CAtomic::assign(T &variable, const T &value)	{
	CAtomic atom(true);
	variable = value;
}


template<class T>
void CAtomic::swap(T &variable1, T &variable2)	{
	CAtomic atom(true);
	T tmp = variable1;
	variable1 = variable2;
	variable2 = tmp;
}

template<class T>
T CAtomic::getVal(const T &variable) {
	CAtomic atom(true);
	T tmp = variable;
	return tmp;
}



template<class T>
T CAtomic::call(T func) {
	CAtomic atom(true);
	return func();
}



};//namespace monos
