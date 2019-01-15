#include "Timer.hpp"






#define STD_PERIOD	1000



namespace tirtos{


UInt CTimer::timers_count = 0;


Void CTimer::handler(UArg a){
	(*FORCE_CAST(TFastFunctor*, a))();
}




CTimer::CTimer(TFastFunctor functor, UInt32 period, bool autostart){
	Clock_Params_init(&params);
	this->functor = functor;
	params.arg = (UArg)&this->functor;
	params.startFlag = autostart;
	params.period = period;

	if(period == 0)
		period = STD_PERIOD;

	handle = Clock_create(&handler, period, &params, NULL);
	if(handle == NULL)
		return;
	timers_count++;
}






CTimer::~CTimer(){
	if(handle == NULL)
		return;
	Clock_delete(&handle);
	timers_count--;
}


void CTimer::setPeriod(UInt32 value){
	Clock_setPeriod(handle, value);
}


UInt32 CTimer::Period(){
	return Clock_getPeriod(handle);
}



void CTimer::start(){
	Clock_start(handle);
}


void CTimer::stop(){
	Clock_stop(handle);
}


UInt CTimer::TimersCount(){
	return timers_count;
}

};
