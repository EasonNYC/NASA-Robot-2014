#include "Timer.h"
#include "Defines.h"

namespace Robot
{
	Timer::Timer()
		:previousTime(0), currentTime(0)
	{}
	void Timer::reset()
	{
		this->previousTime = this->currentTime = 0;
	}
	void Timer::start()
	{
		this->previousTime = millis();
	}
	bool Timer::condition(char c)
	{
		this->currentTime = millis();
		switch (c)
		{
		case 'F':
			return (currentTime - previousTime > 500 ? true : false);
		case 'M':
			return (currentTime - previousTime > 60000 ? true : false);
		case 'S':
			return (currentTime - previousTime > 1000 ? true : false);
		}
	}
}
