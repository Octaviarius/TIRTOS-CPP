/*!
 * \file Swi.hpp
 * \brief Обёртка над Swi-потоком - объектом ОС
 */
#pragma once

#include <ti/sysbios/knl/Swi.h>

#include "ErrorBlock.hpp"
#include "os_types.h"


namespace tirtos{



/*!
 * @brief Обёртка над программными прерываниями
 */
class CSwi{
private:

	//! Ключ включения программных прерываний
	static UInt key;
	//! Хэндл объекта
	Swi_Handle handle;
	//! Параметры
	Swi_Params params;
	//! Блок логгирования ошибок
	CErrorBlock *eb;

	TFastFunctor functor;

	static CErrorBlock eblock;
	static size_t obj_counter;
	static Void handler(UArg, UArg);

public:

	//! Конструктор
	CSwi();
	//! КОнструктор с инициализацией
	CSwi(TFastFunctor functor, Int priority = -1, UInt trigger = 0, CErrorBlock *eb = NULL);

	//! Деструктор
	~CSwi();

	//! Конфигурирование
	void config(TFastFunctor functor, Int priority = -1, UInt trigger = 0, CErrorBlock *eb = NULL);
	//! Принудительный запуск программного прерывания
	void post();

	//! Текущий приоритет
	UInt Priority();

	//! Глобальное выключение программных прерываний
	static void disableSwi();
	//! Глобальное включение программных прерываний
	static void enableSwi();
	//! Хэндл текущего программного прерывания
	static Swi_Handle selfHandle();

};



}
