/*!
 * \file Semaphore.cpp
 * \brief Обёртка над Semaphore - объектом ОС
 */
#include <tirtos/Semaphore.hpp>


namespace tirtos{



CErrorBlock CSemaphore::eblock;
size_t CSemaphore::obj_counter = 0;


CSemaphore::CSemaphore(Int n, CErrorBlock *eb){
	this->eb = (eb == NULL) ? &eblock : eb;

	handle = Semaphore_create(n, NULL, &this->eb->Handle());
	obj_counter++;
}

CSemaphore::~CSemaphore() {
	Semaphore_delete(&handle);
	obj_counter--;
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


