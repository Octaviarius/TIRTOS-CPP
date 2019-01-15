/*!
 * \file Swi.cpp
 * \brief Обёртка над Swi-потоком - объектом ОС
 */

#include "Swi.hpp"



namespace tirtos{




UInt CSwi::key = 0;
CErrorBlock CSwi::eblock;
size_t CSwi::obj_counter = 0;



Void CSwi::handler(UArg a0, UArg a1){
	(*FORCE_CAST(TFastFunctor*, a0))();
}





CSwi::CSwi(){
	handle = 0;
	Swi_Params_init(&params);
	eb = NULL;
}



CSwi::CSwi(TFastFunctor functor, Int priority, UInt trigger, CErrorBlock *eb){
	Swi_Params_init(&params);
	this->functor = functor;
	params.priority = priority;
	params.trigger = trigger;
	params.arg0 = (UArg)&this->functor;
	this->eb = (eb == NULL) ? &eblock : eb;
	handle = Swi_create(&handler, &params, &this->eb->Handle());
	obj_counter++;
}






CSwi::~CSwi(){
	obj_counter--;
}





void CSwi::config(TFastFunctor functor, Int priority, UInt trigger, CErrorBlock *eb){
	Swi_Params_init(&params);
	this->functor = functor;
	params.priority = priority;
	params.trigger = trigger;
	params.arg0 = (UArg)&this->functor;
	this->eb = (eb == NULL) ? &eblock : eb;
	handle = Swi_create(&handler, &params, &this->eb->Handle());
}



void CSwi::post(){
	if(handle != 0){
		Swi_post(handle);
	}
}


UInt CSwi::Priority(){
	if(handle == 0)
		return (UInt)-1;
	return Swi_getPri(handle);
}



Swi_Handle CSwi::selfHandle(){
	return Swi_self();
}




void CSwi::disableSwi(){
	if(key != 0)
		return;
	key = Swi_disable();
}


void CSwi::enableSwi(){
	if(key == 0)
		return;
	Swi_restore(key);
	key = 0;
}



};

