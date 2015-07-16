#ifndef MOTOR_H
#define MOTOR_H

#include "Defines.h"
#include <Sabertooth.h>
#include <SoftwareSerial.h>
#include <SyRenSimplified.h>

namespace Robot
{
	class Motor
	{
	private:
		Sabertooth front; //front motor
		Sabertooth back; //back motor
		SyRenSimplified Pulley; //Pulley System
		SyRenSimplified Actuator; //Linear Actuator
		SoftwareSerial ss; //Pin used for actuator
		SoftwareSerial ss2; //Pin used for pulley
		int wheelPower[4];
		int ActuatorSpeed;
		int PulleySpeed;
	public:
		Motor();
		void forward();
		void reverse();
		void stop();
		void rightTurn();
		void leftTurn();
		void decelerate();
		void Ebrake();
		void setSSBegin();
		void setSS2Begin();
		void linearActuatorUp();
		void linearActuatorDown();
		void linearActuatorStop();
		void pulleyStart();
		void pulleyStop();
		void dig();
		void updateSpeed();
	};
}
#endif
