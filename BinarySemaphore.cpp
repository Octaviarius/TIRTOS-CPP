/*!
 *  \file BinarySemaphore.сpp
 *  \brief Обёртка над бинарным семафором ОС - реализация.
 *
 */

#include "BinarySemaphore.hpp"


namespace tirtos{


TIRTOS_OBJECT_CONSTRUCT(CBinarySemaphore)


/*!
 * \brief Конструктор. Создаю семафор, устанавливаю его в ноль.
 * Инициализация параметров по умолчанию.
 * Создание экземпляра (динамическое). Установка в ноль.
 */
CBinarySemaphore::CBinarySemaphore() {
	Semaphore_Params param;

   	Semaphore_Params_init(&param);
   	param.mode = Semaphore_Mode_BINARY;
	handle = Semaphore_create(0, NULL, NULL);

	_inc_object();
}

/*!
 * \brief Конструктор. Создаю семафор, устанавливаю его в единицу.
 * Инициализация параметров по умолчанию.
 * Создание экземпляра (динамическое). Установка его в единицу.
 */
CBinarySemaphore::CBinarySemaphore(bool checked) {
	Semaphore_Params param;

   	Semaphore_Params_init(&param);
   	param.mode = Semaphore_Mode_BINARY;
	handle = Semaphore_create(checked, NULL, NULL);

	_inc_object();
}

/*!
 * \brief Удаляю семафор.
 */
CBinarySemaphore::~CBinarySemaphore() {
	Semaphore_delete(&handle);
	_dec_object();
}







/*!
 * \brief Отправка семафора ожедающему трэду.
 */
void CBinarySemaphore::release(){
	Semaphore_post(handle);
}


/*!
 * \brief Получаю счётчик семафора.
 */
bool 	CBinarySemaphore::checked(){
	return Semaphore_getCount(handle);
}


/*!
 * \brief - путальница.
 * \todo Исправить на acquire
 */
bool	CBinarySemaphore::acquire(long timeout){
	return Semaphore_pend(handle, timeout);
}



};
