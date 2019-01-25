/*!
 * \file Hwi.cpp
 * \brief Обёртка над HWI - объектом ОС
 */
#include "Hwi.hpp"


namespace tirtos{


TIRTOS_OBJECT_CONSTRUCT(CHwi)


CAtomic CHwi::atom;


Void CHwi::handler(UArg a){
	(*FORCE_CAST(CHwi*, a)).functor();
	(*FORCE_CAST(CHwi*, a)).ints_counter++;
}



CHwi::CHwi(){
	Hwi_Params_init(&params);
	handle = NULL;
	intNum = -1;
	ints_counter = 0;
	_inc_object();
}


CHwi::CHwi(TFastFunctor functor, Int intNum){
	handle = NULL;
	config(functor, intNum);
	_inc_object();
}




CHwi::~CHwi(){
	Hwi_delete(&handle);
	_dec_object();
}




void CHwi::config(TFastFunctor functor, Int intNum){

	if(handle != NULL)
		 Hwi_delete(&handle);

	Hwi_Params_init(&params);
	this->functor = functor;
	params.enableInt = false;
	params.arg = (UArg)this;

	this->intNum = intNum;
	ints_counter = 0;

	handle = Hwi_create(intNum, &handler, &params, &errorBlock()->Handle());
}





void CHwi::enable(){
	if(handle != 0){
		Hwi_enableInterrupt(intNum);
	}
}


void CHwi::disable(){
	if(handle != 0){
		Hwi_disableInterrupt(intNum);
	}
}

void CHwi::selfPost(){
	post(intNum);
}





uint64_t CHwi::interruptsCount(){
	return ints_counter;
}






void CHwi::enableHwi(){
	atom.unlock();
}


void CHwi::disableHwi(){
	atom.lock();
}


void CHwi::startup(){
	Hwi_startup();
}




void CHwi::post(Int intNum){
	Hwi_post(intNum);
}





};
