/*!
 * \file Mutex.hpp
 * \brief Обёртка над Mutex - объектом ОС
 */
#pragma once


#include <tirtos/Atomic.h>
#include <tirtos/Hwi.hpp>


namespace tirtos{



void CAtomic::lock() {
	if(locked == false){
		key = Hwi_disable();
		locked = true;
	}
}


void CAtomic::unlock() {
	if(locked == true){
		locked = false;
		Hwi_restore(key);
	}
}



};//namespace monos
