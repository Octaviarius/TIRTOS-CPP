
#include "Watch.hpp"
#include "Cpu.hpp"




namespace tirtos{


void CWatch::_getTicks(__time64_t *t){
	TimestampProvider_get64((Types_Timestamp64*)t);
	std::swap((*(Types_Timestamp64*)t).hi, (*(Types_Timestamp64*)t).lo);
}



CWatch::CWatch(){
	time_shift = 0;
	time_curr = 0;
}


CWatch::~CWatch(){

}




void CWatch::setTicks(__time64_t value){
	time_curr = value;
	_getTicks(&time_shift);
}



__time64_t CWatch::ticks(){
	__time64_t t;
	_getTicks(&t);
	return t - time_shift + time_curr;
}



void CWatch::setTimeUTC(__time64_t value){
	setTicks((value * __time64_t(CCpu::Rate(0) * 1e18)) / 1000000000);
}



__time64_t CWatch::timeUTC(){
	return (ticks() * 1000000000) / __time64_t(CCpu::Rate(0) * 1e18);
}

void CWatch::stopwatch(){
	_getTicks(&time_curr);
	time_shift = 0;
}


__time64_t CWatch::relativeTicks(){
	__time64_t t;
	_getTicks(&t);
	return t - time_curr;
}



__time64_t CWatch::relativeTimeUTC(){
	return (relativeTicks() * 1000000000) / __time64_t(CCpu::Rate(0) * 1e18);
}

float CWatch::relativeTimeUTCf(){
	__time64_t t;
	_getTicks(&t);
	return float(t - time_curr) * CCpu::Rate(0);
}




__time64_t CWatch::globalTicks(){
	__time64_t t;
	_getTicks(&t);
	return t;
}


__time64_t CWatch::globalTimeUTC(){
	__time64_t t;
	_getTicks(&t);
	return t;
}



};
