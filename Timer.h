#ifndef TIMER_H
#define TIMER_H

#include "Defines.h"
namespace Robot
{
	class Timer
	{
	private:
		unsigned long previousTime;
		unsigned long currentTime;
	public:
		Timer();
		void reset();
		void start();
		bool condition(char);
	};
}
#endif
