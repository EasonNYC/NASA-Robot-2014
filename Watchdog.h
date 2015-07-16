#ifndef WATCHDOG_H
#define WATCHDOG_H

#include "Defines.h";

namespace Robot
{
	class Timer;
	class Wifly;
	class Watchdog
	{
	private:
		bool isConnected;
		unsigned long currentTime;
		unsigned long previousTime;
		Wifly* wifly;
		Timer* timer;
	public:
		Watchdog(Wifly& wifly, Timer& timer);
		void reset();
		void check();
	};
}
#endif
