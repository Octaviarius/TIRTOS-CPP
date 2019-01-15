#pragma once

#include <stdint.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/BIOS.h>
#include "ErrorBlock.hpp"



namespace tirtos {



class CEvent {
private:
	Event_Handle handle;
	Event_Params params;
	static CErrorBlock eblock;
public:

	CEvent(CErrorBlock *eb = NULL);
	~CEvent();

	//! Post event to system
	void post(uint32_t event);
	//! Wait for events combination
	bool wait(uint32_t orMask, uint32_t andMask = 0, long timeout = BIOS_WAIT_FOREVER);

};



} /* namespace os */





