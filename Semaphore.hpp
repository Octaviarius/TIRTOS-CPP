/*!
 * \file Semaphore.hpp
 * \brief Обёртка над Semaphore - объектом ОС
 */

#pragma once


#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/BIOS.h>
#include "common.h"



namespace tirtos{



/*!
 * @brief Семафор
 */
class CSemaphore {
    TIRTOS_OBJECT
private:
	//! Хэндл объекта
	Semaphore_Handle handle;
public:

	//! Конструктор
	CSemaphore(Int n = 0);
	//! Деструктор
	~CSemaphore();

	//! Отпускание семафора
	void release();
	//! Сброс семафора
	void reset(Int count = 0);

	//! текущее количество захватов
	int available();

	//! Заъват с ожиданием
	bool acquire(long timeout = BIOS_WAIT_FOREVER);


};








}
