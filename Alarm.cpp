#include "Communication.h"
#include "Alarm.h"

namespace Robot
{
	Alarms::Alarms() //initialize all arrays to zero and comm pointer to null since communications needs an alarm ref to initialize
		:comm(NULL)
	{}
	void Alarms::send(int code) //takes in an integer input and sends all qued messages, adds the alarm code and then sends that
	{
		if (comm) //only run if comm pointer is set
		{
			comm->sendComm();	//flush the cue
			comm->addComm('!', 2, NULL, &code);	//add the alarm to the cue
			comm->sendComm();	//send the cue with the alarm
		}
	}
	void Alarms::setComms(Communication& comm)		//when you get a chance explain why this doesnt happen in the constructor instead.
	{
		this->comm = &comm;
	}
}
