/*
 * CEvent.cpp
 *
 *  Created on: 30 авг. 2017 г.
 *      Author: Gomanchuk_AS
 */

#include "Event.hpp"


namespace tirtos {


TIRTOS_OBJECT_CONSTRUCT(CEvent)



CEvent::CEvent() {
	Event_Params_init(&params);
	handle = Event_create(&params, &errorBlock()->Handle());
	_inc_object();
}

CEvent::~CEvent() {
	Event_delete(&handle);
	_dec_object();
}




void CEvent::post(uint32_t event){
	Event_post(handle, event);
}



bool CEvent::wait(uint32_t orMask, uint32_t andMask, long timeout){
	return Event_pend(handle, andMask, orMask, timeout);
}




} /* namespace os */
