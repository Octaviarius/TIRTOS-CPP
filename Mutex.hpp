/*!
 * \file Mutex.hpp
 * \brief Обёртка над Mutex - объектом ОС
 */
#pragma once


#include <ti/sysbios/gates/GateAll.h>



namespace tirtos{


/*!
 * @brief Мьютекс
 */
class CMutex{
private:
	//! Хэндл объекта
	GateAll_Handle mutex;
public:

	inline CMutex()		{mutex = GateAll_create(NULL, NULL);}
	inline ~CMutex()	{GateAll_delete(&mutex);}
	inline void lock()	{GateAll_enter(mutex);}
	inline void unlock(){GateAll_leave(mutex, 0);}

};



};
