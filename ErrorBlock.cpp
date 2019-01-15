/*!
 * \file ErrorBlock.cpp  .
 * \brief Реализация класса-обёртки над структурой, в которую помещается код и расшифровка ошибки SYS/BIOS .
 */

#include "ErrorBlock.hpp"

namespace tirtos{


/*!
 * \brief Конструктор.
 * Загружаю начальные параметры в структуру типа  xdc_runtime_Error_Block .
 */
CErrorBlock::CErrorBlock(){
	Error_init(&handle);
}

/*!
 * \brief Деструктор, не делаю ничего.
 *
 */
CErrorBlock::~CErrorBlock(){

}

/*!
 * \brief Возвращаю указатель на структуру:
 *
 * \code
 * struct xdc_runtime_Error_Block
 * {
 *    xdc_UInt16 unused;
 *    xdc_runtime_Error_Data data;
 *    xdc_runtime_Error_Id id;  //идентификатор ошибки
 *    xdc_String msg; //описание ошибки
 *    xdc_runtime_Types_Site site;
 *    __TA_xdc_runtime_Error_Block__xtra xtra;
 * };
 * \endcode
 *
 */
Error_Block &CErrorBlock::Handle(){
	return handle;
}


void CErrorBlock::print(){
	Error_print(&handle);
}

void CErrorBlock::raise(uint32_t id, uint32_t arg0, uint32_t arg1){
	Error_raise(&handle, id, arg0, arg1);
};


bool CErrorBlock::check(){
	return Error_check(&handle) != 0;
}


uint16_t CErrorBlock::getCode(){
	return Error_getCode(&handle);
}


char *CErrorBlock::getMsg(){
	return Error_getMsg(&handle);
}


};//nmaspace os
