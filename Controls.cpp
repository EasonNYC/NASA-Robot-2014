#include "Motor.h"
#include "Controls.h"
#include "Communication.h"

namespace Robot
{
	//constructor
	Controls::Controls(Motor& motor)
		:motor(&motor), dpad(-1), triggers(0)
	{
		for (int i = 0; i<7; i++)
			buttons[i] = 1; //initialize buttons to one upon change button will be one
	}
	int Controls::BitReadCombine(unsigned int x_high, unsigned int x_low)
	{
		int x;
		for (int t = 7; t >= 0; t--)
		{
			bitWrite(x, t, bitRead(x_low, t));
		}
		for (int t = 7; t >= 0; t--)
		{
			bitWrite(x, t + 8, bitRead(x_high, t));
		}
		return x;
	}
	void Controls::updateControls(char* arr) //takes in input from wifly
	{
		if (arr[0] == '#') //if its a controller message
		{
			byte temp = arr[1];
			for (int i = 0; i < 8; i++)
				buttons[i] = bitRead(temp, i); //change button values
			dpad = BitReadCombine(arr[2], arr[3]); //change dpad
			triggers = -1 * arr[4]; //change trigger
			//this->display(); //debug control system
		}
		this->updateDriving();
		this->updateActuators();
		this->updatePulley();
		this->updateDigging();
		this->updateSystemMessages();
	} //gets controls from input arr and updates the corresponding values
	void Controls::display() const
	{
		Serial.print("Dpad: ");
		Serial.print(dpad);
		Serial.println(" ");
		Serial.print("Triggers: ");
		Serial.print(triggers);
		Serial.println(" ");
		Serial.print("Buttons: ");
		for (int i = 0; i < 8; i++)
			Serial.print(buttons[i]);
		Serial.println(" ");
	}
	void Controls::updateActuators() //m1 blk m2 red
	{
		if (!buttons[RB])
		{
			this->ACode = 7;
			//int x = analogRead(Actuator1);
			//int y = analogRead(Actuator2);
			//int z[2] = { x, y };
			//comm->addComm('^', 4, NULL, z);
			this->motor->linearActuatorUp();
		}
		if (!buttons[LB])
		{
			this->ACode = 8;
			//int x = analogRead(Actuator1);
			//int y = analogRead(Actuator2);
			//int z[2] = { x, y };
			//comm->addComm('^', 4, NULL, z);
			this->motor->linearActuatorDown();
		}
		if (buttons[LB] && buttons[RB])
		{
			this->motor->linearActuatorStop();
		}
	}
	void Controls::updateDriving()
	{
		if (!buttons[A])
		{
			this->MCode = 1;
			this->motor->forward();
			return;
		}
		if (!buttons[B])
		{
			this->MCode = 2;
			this->motor->reverse();
			return;
		}
		if (dpad == 90)
		{
			this->MCode = 3;
			this->motor->rightTurn();
			return;
		}
		if (dpad == 270)
		{
			this->MCode = 4;
			this->motor->leftTurn();
			return;
		}
		if (!buttons[Back])
		{
			this->MCode = 9;
			this->motor->stop();
			return;
		}
	} // updates motor speeds as well as sends action by action of what the robot is doing
	void Controls::updatePulley()
	{
		if (!buttons[Y])
		{
			this->PCode = 6;
			this->motor->pulleyStart();
		}
		else
		{
			this->PCode = 7;
			this->motor->pulleyStop();
		}
	}
	void Controls::updateDigging()
	{
		if (!buttons[X])
		{
			this->DCode = 5;
			this->motor->dig();
			return;
		}
		else
		{
			this->DCode = 6;
			return;
		}
	}
	void Controls::setComm(Communication& comm) //sets comm pointer
	{
		this->comm = &comm;
	}
	void Controls::updateSystemMessages()
	{
		if (prevACode != ACode)
		{
			comm->addComm('%', 1, &ACode);
			prevACode = ACode;
		}
		if (prevDCode != DCode)
		{
			if (DCode == 5)
			{
				comm->addComm('%', 1, &DCode);
				prevDCode = DCode;
			}
		}
		if (prevMCode != MCode)
		{
			comm->addComm('%', 1, &MCode);
			prevMCode = MCode;
		}
		if (prevPCode != PCode)
		{
			comm->addComm('%', 1, &PCode);
			prevPCode = PCode;
		}
	}
}
