/*!
 * \file MutexLocker.hpp
 * \brief Реализация класса MutexLocker. Обёртка над Mutex
 */
#pragma once

#include "Mutex.hpp"



namespace tirtos{


class CMutexLocker{
private:
	CMutex *mutex;
public:

	inline CMutexLocker(CMutex *mutex){
		this->mutex = mutex;
		mutex->lock();
	}

	inline ~CMutexLocker(){mutex->unlock();}

	inline void lock()	{mutex->lock();}
	inline void unlock()	{mutex->unlock();}


};




};
