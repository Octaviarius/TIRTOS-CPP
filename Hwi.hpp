/*!
 * \file Hwi.hpp
 * \brief Обёртка над HWI - объектом ОС
 */

#pragma once

#include <ti/sysbios/interfaces/IHwi.h>
#include <ti/sysbios/family/c28/Hwi.h>

#include "Atomic.h"
#include "ErrorBlock.hpp"
#include "os_types.h"


namespace tirtos{


/*!
 * @brief Обёртка над аппратным прерываниями
 */
class CHwi{
private:

	//! Хэндл объёекта
	Hwi_Handle handle;
	//! Параметры
	Hwi_Params params;
	//! Номер подключаемого прерывания
	Int intNum;
	uint64_t 	ints_counter;
	//! Блок лога ошибок
	CErrorBlock *eb;

	TFastFunctor functor;


	//! Ключ для управления состоянием глобальных прерываний
	static CAtomic atom;

	static CErrorBlock eblock;
	static size_t obj_counter;
	static Void handler(UArg);

public:

	//! Конструктор с инициализацией
	CHwi();
	CHwi(TFastFunctor functor, Int intNum, CErrorBlock *eb = NULL);
	//! Деструктор
	~CHwi();

	//! Конфигурирование
	void config(TFastFunctor meth, Int intNum, CErrorBlock *eb = NULL);
	//! Включение прерывания
	void enable();
	//! Выключение прерывания
	void disable();
	//! Генерация пре
	void selfPost();

	uint64_t interruptsCount();

	//! Включение глобальных прерываний
	static void enableHwi();
	//! Выключение глобальных прерываний
	static void disableHwi();
	//! Инициализация прерываний
	static void startup();
	//! Генерация заданного номера прерывания
	static void post(Int intNum);

};


};
