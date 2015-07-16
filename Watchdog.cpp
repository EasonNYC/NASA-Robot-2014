#include "Wifly.h"
#include "Watchdog.h"
#include "Timer.h"

namespace Robot
{
	Watchdog::Watchdog(Wifly& wifly, Timer& timer)
		:isConnected(true), previousTime(millis()), currentTime(0), wifly(&wifly), timer(&timer)
	{}
	void Watchdog::reset()
	{
		isConnected = true;
		previousTime = millis();
		timer->reset();
	}
	void Watchdog::check()
	{
		currentTime = millis();
		if (currentTime - previousTime > INTERVALWDT)
		{
			if (isConnected == true)
			{
				isConnected = false;
				previousTime = currentTime;
				timer->start();
			}
			else
			{
				if (timer->condition('M'))
					wifly->reboot();
			}
		}
	}
}
