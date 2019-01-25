/*!
 * \file Hwi.hpp
 * \brief Обёртка над HWI - объектом ОС
 */

#pragma once

#include <ti/sysbios/interfaces/IHwi.h>
#include <ti/sysbios/family/c28/Hwi.h>

#include "Atomic.h"
#include "common.h"


namespace tirtos{


/*!
 * @brief Обёртка над аппратным прерываниями
 */
class CHwi{
    TIRTOS_OBJECT
private:

	//! Хэндл объёекта
	Hwi_Handle handle;
	//! Параметры
	Hwi_Params params;
	//! Номер подключаемого прерывания
	Int intNum;
	uint64_t 	ints_counter;

	TFastFunctor functor;

	//! Ключ для управления состоянием глобальных прерываний
	static CAtomic atom;
	static Void handler(UArg);

public:

	//! Конструктор с инициализацией
	CHwi();
	CHwi(TFastFunctor functor, Int intNum);
	//! Деструктор
	~CHwi();

	//! Конфигурирование
	void config(TFastFunctor meth, Int intNum);
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
