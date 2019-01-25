#pragma once


#include <ti/sysbios/knl/Clock.h>
#include "common.h"




namespace tirtos{


class CTimer {
    TIRTOS_OBJECT
private:

	Clock_Handle handle;
	Clock_Params params;

	TFastFunctor functor;

	static Void handler(UArg);
public:

	CTimer(TFastFunctor functor, UInt32 period = 0, bool autostart = false);
	~CTimer();

	void setPeriod(UInt32 value);
	UInt32 Period();

	void start();
	void stop();

	bool isActive();

	bool isOneshot();
	void enableOneshot(bool value);


};


};
