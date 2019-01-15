/*!
 * \file ErrorBlock.hpp
 * \brief Определение класса-обёртки над структурой, в которую помещается код и расшифровка ошибки SYS/BIOS .
 */
#pragma once


#include <xdc/runtime/Error.h>



namespace tirtos{

/*!
 * \brief Класс-обёртка над структурой, в которую помещается код и расшифровка ошибки SYS/BIOS .
 */
class CErrorBlock{
private:


	Error_Block handle;

public:

	CErrorBlock();
	~CErrorBlock();

	Error_Block &Handle();

	void print();
	void raise(uint32_t id, uint32_t arg0, uint32_t arg1);

	bool check();
	uint16_t getCode();
	char *getMsg();

};




};
