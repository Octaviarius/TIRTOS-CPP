/*!
 * \file Swi.cpp
 * \brief Обёртка над Swi-потоком - объектом ОС
 */

#include "Swi.hpp"



namespace tirtos{


TIRTOS_OBJECT_CONSTRUCT(CSwi)

UInt CSwi::key = 0;



Void CSwi::handler(UArg a0, UArg a1){
	(*FORCE_CAST(TFastFunctor*, a1))();
}





CSwi::CSwi(){
	handle = 0;
	Swi_Params_init(&params);
    handle = Swi_create(&handler, &params, &errorBlock()->Handle());
	_inc_object();
}



CSwi::CSwi(TFastFunctor functor, Int priority, UInt trigger){
	Swi_Params_init(&params);
	this->functor = functor;
	params.priority = priority;
	params.trigger = trigger;
	params.arg0 = (UArg)this;
    params.arg1 = (UArg)&this->functor;
	handle = Swi_create(&handler, &params, &errorBlock()->Handle());
	_inc_object();
}






CSwi::~CSwi(){
	_dec_object();
}





void CSwi::config(TFastFunctor functor, Int priority, UInt trigger){
	this->functor = functor;
	params.priority = priority;
	params.trigger = trigger;
    params.arg0 = (UArg)this;
    params.arg1 = (UArg)&this->functor;
	Swi_setAttrs(handle, nullptr, &params);
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

