#include "Communication.h"
#include "Heartbeat.h"

namespace Robot
{
	Heartbeat::Heartbeat(Communication& comm)
		:comm(&comm), previousTime(millis()), currentTime(0)
	{}
	void Heartbeat::reset()
	{
		previousTime = millis();
		currentTime = 0;
	}
	void Heartbeat::send()
	{
		currentTime = millis();
		if (currentTime - previousTime > INTERVALHB)
		{
			byte x = 255;
			comm->addComm('&', 1, &x);
			previousTime = currentTime;
		}
	}
}
