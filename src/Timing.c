/* Timing.c
 *
 */

#if defined (_MSC_VER)
// do things the Windows way
#include <Windows.h>
static LARGE_INTEGER _freq;
#else
// do things in less-Windowsy ways
#include <unistd.h>
#include <time.h>
#if defined __MACH__
// ...the macOS way
#include <mach/mach.h>
#include <mach/clock.h>
#elif !defined CLOCK_MONOTONIC_RAW
// ...the BSD way
#include <sys/time.h>
#endif // ndef CLOCK_MONOTONIC_RAW
#endif //_MSC_VER

#include "Timing.h"

double GetTimeInMsec() {
	return GetTimeInUsec()/1000.0;
}

double GetTimeInUsec() {
	double retval = 0;
#if defined __MACH__
	//mach-specific code follows
	clock_serv_t cclock;
	mach_timespec_t mts;
	host_get_clock_service(mach_host_self(), REALTIME_CLOCK, &cclock);
	clock_get_time(cclock, &mts);
	mach_port_deallocate(mach_task_self(), cclock);
	retval = mts.tv_sec * 1000000.0;
	retval += mts.tv_nsec / 1000.0;
#elif defined CLOCK_MONOTONIC_RAW
	//linux-specific code follows
	struct timespec currentTime;
	clock_gettime(CLOCK_MONOTONIC_RAW, &currentTime);
	retval = currentTime.tv_sec * 1000000.0;
	retval += currentTime.tv_nsec / 1000.0;
#elif defined (_MSC_VER)
	//Windows-specific code follows
	if (_freq.QuadPart == 0)
		QueryPerformanceFrequency(&_freq);
	LARGE_INTEGER currentTime;
	QueryPerformanceCounter(&currentTime);
	retval = currentTime.QuadPart / _freq.QuadPart;
#else
	//more generic code here:
	struct timeval currentTime;
	gettimeofday(&currentTime, 0);
	retval = currentTime.tv_sec * 1000000.0;
	retval += currentTime.tv_usec;
#endif
	return retval;
}

void SleepMsec(double ms) {
	if(ms > 0) usleep((int)(ms*1000.0));
}

void SleepUsec(int us) {
	if(us > 0) usleep(us);
}

