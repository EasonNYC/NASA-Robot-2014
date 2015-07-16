#ifndef ALARM_H
#define ALARM_H

#include "Defines.h"

namespace Robot
{
	class Communication;

	class Alarms
	{
	private:
		Communication* comm; //communications pointer to send messages
	public:
		Alarms();
		void send(int code);
		void setComms(Communication& comm);
	};
}
#endif
