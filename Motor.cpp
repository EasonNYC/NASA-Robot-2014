#include "Motor.h"

namespace Robot
{
	Motor::Motor() //initialize front and back motors / must initialize SoftwareSerial Pin first then initialize Actuator with Serial Pin
		:front(frontAddress, Serial2), back(backAddress, Serial2), ss(NOT_A_PIN, SyrenPin), ss2(NOT_A_PIN, PulleyPin), Actuator(ss), Pulley(ss2), ActuatorSpeed(0), PulleySpeed(0)
	{
		for (int i = 0; i < 4; ++i)
			wheelPower[i] = 0;
		this->updateSpeed();
	}
	void Motor::updateSpeed()
	{
		front.motor(right, wheelPower[frontRight]);
		front.motor(left, wheelPower[frontLeft]);
		back.motor(right, wheelPower[backRight]);
		back.motor(left, wheelPower[backLeft]);
	}
	void Motor::decelerate()
	{
		for (int i = 0; i < 4; i++)
		{
			if (wheelPower[i] != 0)
			{
				(wheelPower[i] > 0 ? wheelPower[i] -= DeltaRamp : wheelPower[i] += DeltaRamp);
			}
			else
				continue;
		}
	}
	void Motor::forward()
	{
		wheelPower[frontLeft] += DeltaRamp * 2; //
		wheelPower[frontRight] -= DeltaRamp * 2; //FL white
		wheelPower[backLeft] += DeltaRamp * 2;
		wheelPower[backRight] -= DeltaRamp * 2;
		this->updateSpeed();
	}
	void Motor::reverse()
	{
		wheelPower[frontRight] += DeltaRamp * 2;
		wheelPower[frontLeft] -= DeltaRamp * 2;
		wheelPower[backRight] += DeltaRamp * 2;
		wheelPower[backLeft] -= DeltaRamp * 2;
		this->updateSpeed();
	}
	void Motor::stop()
	{
		wheelPower[frontRight] = 0;
		wheelPower[frontLeft] = 0;
		wheelPower[backRight] = 0;
		wheelPower[backLeft] = 0;
		this->updateSpeed();
	}
	void Motor::rightTurn()
	{
		wheelPower[frontRight] -= DeltaRamp * 2;
		wheelPower[frontLeft] -= DeltaRamp * 2;
		wheelPower[backRight] += DeltaRamp * 2;
		wheelPower[backLeft] += DeltaRamp * 2;
		this->updateSpeed();
	}
	void Motor::leftTurn()
	{
		wheelPower[frontRight] += DeltaRamp * 2; //FL
		wheelPower[frontLeft] += DeltaRamp * 2; //FR
			wheelPower[backRight] -= DeltaRamp * 2;
			wheelPower[backLeft] -= DeltaRamp * 2;
		this->updateSpeed();
	}
	void Motor::Ebrake() //sets all motors to zero
	{
		front.motor(right, 0);
		front.motor(left, 0);
		back.motor(right, 0);
		back.motor(left, 0);
		Actuator.motor(0);
		Pulley.motor(0);
	}
	void Motor::setSSBegin() //in order to utilize SoftwareSerial pin must begin at a baud rate
	{
		ss.begin(9600);
	}
	void Motor::setSS2Begin()
	{
		ss2.begin(9600);
	}
	void Motor::linearActuatorUp()
	{
		if (ActuatorSpeed <= 127)
			ActuatorSpeed += DeltaRamp;
		Actuator.motor(ActuatorSpeed);
	}
	void Motor::linearActuatorDown()
	{
		if (ActuatorSpeed >= -127)
			ActuatorSpeed -= DeltaRamp;
		this->Actuator.motor(ActuatorSpeed);
	}
	void Motor::linearActuatorStop()
	{
		ActuatorSpeed = 0;
		Actuator.motor(ActuatorSpeed);
	}
	void Motor::pulleyStart()
	{
		if (PulleySpeed <= 127)
			PulleySpeed += DeltaRamp;
		this->Pulley.motor(PulleySpeed);
	}
	void Motor::pulleyStop()
	{
		PulleySpeed = 0;
		this->Pulley.motor(PulleySpeed);
	}
	void Motor::dig()
	{
		if (wheelPower[frontRight] <= 75)
			wheelPower[frontRight] += DeltaRamp * 2;
		if (wheelPower[frontLeft] >= -75)
			wheelPower[frontLeft] -= DeltaRamp * 2;
		wheelPower[backLeft] += DeltaRamp * 2;
		wheelPower[backRight] -= DeltaRamp * 2;
		this->updateSpeed();
	}
}
