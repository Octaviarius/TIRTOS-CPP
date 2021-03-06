/*!
 *  \file BinarySemaphore.cpp
 *  \brief Обёртка над бинарным семафором ОС - определения.
 *
 */

#pragma once


#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/BIOS.h>
#include "common.h"



namespace tirtos{


/*!
 * \brief Обёртка над бинарным семафором.
 */
class CBinarySemaphore {
    TIRTOS_OBJECT
private:
	Semaphore_Handle handle;
public:

	CBinarySemaphore();
	CBinarySemaphore(bool checked);
	~CBinarySemaphore();

	void release();
	bool checked();
	bool acquire(long timeout = BIOS_WAIT_FOREVER);

};





}
