/*!
 * \file Semaphore.cpp
 * \brief Обёртка над Semaphore - объектом ОС
 */
#include "Semaphore.hpp"


namespace tirtos{


TIRTOS_OBJECT_CONSTRUCT(CSemaphore)


CSemaphore::CSemaphore(Int n){
	handle = Semaphore_create(n, NULL, &errorBlock()->Handle());
	_inc_object();
}

CSemaphore::~CSemaphore() {
	Semaphore_delete(&handle);
	_dec_object();
}




void CSemaphore::release(){
	Semaphore_post(handle);
}



int CSemaphore::available(){
	return Semaphore_getCount(handle);
}

void CSemaphore::reset(Int count){
	Semaphore_reset(handle, count);
}


bool CSemaphore::acquire(long timeout){
	return Semaphore_pend(handle, timeout);
}





};


