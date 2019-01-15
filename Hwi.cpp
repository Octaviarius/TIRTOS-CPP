/*!
 * \file Hwi.cpp
 * \brief Обёртка над HWI - объектом ОС
 */
#include "Hwi.hpp"


namespace tirtos{



CAtomic CHwi::atom;
CErrorBlock CHwi::eblock;
size_t CHwi::obj_counter = 0;


Void CHwi::handler(UArg a){
	(*FORCE_CAST(CHwi*, a)).functor();
	(*FORCE_CAST(CHwi*, a)).ints_counter++;
}



CHwi::CHwi(){
	Hwi_Params_init(&params);
	handle = NULL;
	intNum = -1;
	ints_counter = 0;
	eb = NULL;
	obj_counter++;
}


CHwi::CHwi(TFastFunctor functor, Int intNum, CErrorBlock *eb){
	handle = NULL;
	config(functor, intNum, eb);
	obj_counter++;
}




CHwi::~CHwi(){
	Hwi_delete(&handle);
	obj_counter--;
}




void CHwi::config(TFastFunctor functor, Int intNum, CErrorBlock *eb){

	if(handle != NULL)
		 Hwi_delete(&handle);

	Hwi_Params_init(&params);
	this->functor = functor;
	params.enableInt = false;
	params.arg = (UArg)this;

	this->intNum = intNum;
	this->eb = (eb == NULL) ? &eblock : eb;
	ints_counter = 0;

	handle = Hwi_create(intNum, &handler, &params, &this->eb->Handle());
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
