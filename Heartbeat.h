#ifndef HEARTBEAT_H
#define HEARTBEAT_H

#include "Defines.h"

namespace Robot
{
	class Communication;

	class Heartbeat
	{
	private:
		unsigned long previousTime;
		unsigned long currentTime;
		Communication* comm;
	public:
		Heartbeat(Communication& comm);
		void send();
		void reset();
	};
}
#endif