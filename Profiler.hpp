#pragma once


#include <stdint.h>
#include "Watch.hpp"
#include "Cpu.hpp"

namespace tirtos{


class CProfiler{
private:
	CWatch 		watch;
	uint64_t 	calls;
	float		last_period_flt;
	__time64_t	last_period;
	bool 		is_active;
public:

	CProfiler()		{
		reset();
	}

	~CProfiler()	{

	};

	void start(){
		if(is_active)
			return;
		is_active = true;
		watch.stopwatch();
	}

	void stop(){
		if(!is_active)
			return;
		last_period = watch.relativeTicks();
		last_period_flt = float(last_period) * CCpu::Rate(0);
		calls++;
		is_active = false;
	}


	void reset(){
		calls = 0;
		last_period_flt = 0.0;
		last_period = 0;
		is_active = false;
	}


	uint64_t callsCount(){
		return calls;
	}

	float time(){
		return last_period_flt;
	}

	__time64_t ticks(){
		return last_period;
	}

};




};
