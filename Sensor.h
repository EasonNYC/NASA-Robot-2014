#ifndef SENSOR_H
#define SENSOR_H

#include "Defines.h"
namespace Robot
{
	class Communication;
	class Motor;
	class Alarms;
	class Sensor
	{
	private:
		int mainVC[2];
		int motorCurrentSensors[5];
		int maxMainCurrent;
		int minMainCurrent;
		int minMainVoltage;
		int maxMotorCurrent;
		int minMotorCurrent;
		Communication* comm;
		Motor* motor;
		Alarms* alarm;
		long currentMStime;
		long prevMStime;
		long currentMtime;
		long prevMtime;
	public:
		Sensor(Communication& comm, Motor& motor, Alarms& alarm); 	//constructor
		void send();					//sends sensor data to labview 
		//void display() const;			//for debug
		int getVoltage();
		int getMCurrent();
		int* getMotorCurrents();
		void checkMotorOverCurrent(int* arr);

	};
}
#endif
