#include "Communication.h"
#include "Sensor.h"
#include "Alarm.h"
#include "Motor.h"
namespace Robot
{
	Sensor::Sensor(Communication& comm, Motor& motor, Alarms& alarm)
		:comm(&comm), motor(&motor), alarm(&alarm), prevMStime(millis()), prevMtime(millis()), currentMStime(0), currentMtime(0)
	{
		this->maxMainCurrent = 14.9 * 30;
		this->minMainCurrent = 14.9*-30;
		this->minMainVoltage = 49.44*9.6;
		this->maxMotorCurrent = (512 + 13.5168 * 30);
		this->minMotorCurrent = (512 + 13.5168*-30);
	}
	void Sensor::send()
	{
		currentMStime = currentMtime = millis();
		if (currentMStime - prevMStime > INTERVALCUR)
		{
			mainVC[0] = this->getVoltage();
			mainVC[1] = this->getMCurrent();
			comm->addComm('V', 4, NULL, mainVC);
			prevMStime = currentMStime;
		}
		if (currentMtime - prevMtime > INTERVALCUR)
		{
			int* arrs = this->getMotorCurrents();
			//this->checkMotorOverCurrent(arrs);
			comm->addComm('C', 8, NULL, arrs);
			prevMtime = currentMtime;
		}
	}
	int Sensor::getVoltage()
	{
		int x = analogRead(A0);
		return x;
	}
	int Sensor::getMCurrent()
	{
		return (int)analogRead(A1);
	}
	int* Sensor::getMotorCurrents()
	{
		int arr[5] = { analogRead(A2), analogRead(A3), analogRead(A4), analogRead(A5), analogRead(A6) };
		return arr;
	}
	void Sensor::checkMotorOverCurrent(int* arr)
	{
		for (int i = 0; i < 5; i++)
		{
			if (arr[i] >= this->maxMotorCurrent)
			{
				int i = 0;
				while (i < 200)
				{
					motor->stop();
					i++;
				}
				alarm->send(3);
				break;
			}
		}
	}
}
