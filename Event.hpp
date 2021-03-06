#pragma once

#include <stdint.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/BIOS.h>
#include "common.h"



namespace tirtos {



class CEvent {
    TIRTOS_OBJECT
private:
	Event_Handle handle;
	Event_Params params;
public:

	CEvent();
	~CEvent();

	//! Post event to system
	void post(uint32_t event);
	//! Wait for events combination
	bool wait(uint32_t orMask, uint32_t andMask = 0, long timeout = BIOS_WAIT_FOREVER);

};



} /* namespace os */





