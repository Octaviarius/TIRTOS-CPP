/*!
 * \file Hwi.hpp
 * \brief Обёртка над HWI - объектом ОС
 */

#pragma once

#include "os_types.h"
#include <time.h>
#include <algorithm>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/family/c28/TimestampProvider.h>

#include <DSP28x_Project.h>





namespace tirtos{



class CWatch{
public:

	enum Month{
		January,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};

	enum WeekDay{
		Sunday,
		Monday,
		Tuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday
	};

	struct TDateTime{
		long nanosecond;
		char second;
		char minute;
		char hour;
		short day;
		Month month;
		short year;
		WeekDay weekday;
	};


private:
	__time64_t time_curr;
	__time64_t time_shift;

	static void _getTicks(__time64_t *t);

public:

	CWatch();
	~CWatch();

	//! set ticks offset
	void setTicks(__time64_t value);
	__time64_t ticks();

	//! set UTC offset in nanoseconds
	void setTimeUTC(__time64_t value);
	__time64_t timeUTC();

	//! set current time for measurement time intervals
	void stopwatch();

	//! calc diffenece from current and shifted ticks count
	__time64_t relativeTicks();
	//! calc diffenece from current and shifted UTC in nanoseconds
	__time64_t relativeTimeUTC();
	//! calc diffenece from current and shifted UTC in seconds
	float relativeTimeUTCf();

	static __time64_t globalTicks();
	static __time64_t globalTimeUTC();

};


};
