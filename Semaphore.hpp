/*!
 * \file Semaphore.hpp
 * \brief Обёртка над Semaphore - объектом ОС
 */

#pragma once


#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/BIOS.h>
#include "../tirtos/ErrorBlock.hpp"



namespace tirtos{



/*!
 * @brief Семафор
 */
class CSemaphore {
private:
	//! Хэндл объекта
	Semaphore_Handle handle;
	CErrorBlock *eb;
	static CErrorBlock eblock;
	static size_t obj_counter;
public:

	//! Конструктор
	CSemaphore(Int n = 0, CErrorBlock *eb = NULL);
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
