/*
 * CEvent.cpp
 *
 *  Created on: 30 авг. 2017 г.
 *      Author: Gomanchuk_AS
 */

#include <tirtos/Event.hpp>


namespace tirtos {


CErrorBlock CEvent::eblock = CErrorBlock();



CEvent::CEvent(CErrorBlock *eb) {
	if(eb == NULL)
		eb = &eblock;
	Event_Params_init(&params);
	handle = Event_create(&params, &eb->Handle());
}

CEvent::~CEvent() {
	Event_delete(&handle);
}




void CEvent::post(uint32_t event){
	Event_post(handle, event);
}



bool CEvent::wait(uint32_t orMask, uint32_t andMask, long timeout){
	return Event_pend(handle, andMask, orMask, timeout);
}




} /* namespace os */
