#pragma once

#include <useful_header.h>



namespace tirtos{



typedef int (*TCallbackFunction)(void *);
typedef CFunctor1<void*, int> TCallbackFunctor;
typedef CFunctor0<void> TFastFunctor;








};//namespace os
