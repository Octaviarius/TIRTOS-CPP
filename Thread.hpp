/*!
 * \file Thread.hpp
 * \brief Обёртка над Task-потоком - объектом ОС
 */
#pragma once

#include <ti/sysbios/knl/Task.h>
#include "common.h"



namespace tirtos{






/*!
 * @brief Обёртка вокруг потока.
 */
class CThread {
    TIRTOS_OBJECT
private:

	struct TCallContext{
		void *arg;
		TCallbackFunctor meth;
		int result;
	};


	//! Хэндл объекта
	Task_Handle handle;
	//! Параметры
	Task_Params params;

	TCallContext call_context;
	void *sender;

	static UInt key;
	static Void handler(UArg, UArg);

public:

	//! Конструктор с инициализацией
	CThread(TCallbackFunctor method, void *arg = NULL, int priority = -1, long stacksize = 0);
	//! Деструктор
	~CThread();

	//! Хэндл
	Task_Handle &Handle();

	//! Установка приоритета задачи
	void setPriority(Int value);
	//! Приоритет задачи
	Int Priority();

	//! Возвращает результат выполнения функции
	long Result();

	//! Включение планировщика задач
	static void enableSheduler();
	//! Выключение планировщика задач
	static void disableSheduler();

	//! Хэндл текущей задачи
	static Task_Handle selfHandle();
	//! Засыпание
	static void suspend();
	//! Засыпание на время (мс)
	static void sleep(long ms);
	//! Засыпание на время (мкс)
	static void sleep_us(long us);
	//! Уничтожение потока
	static void terminate();
	//! Смена потока
	static void yield();

	static CThread &CurrentThread();
};




};
