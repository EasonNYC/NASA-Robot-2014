#ifndef CONTROLS_H
#define CONTROLS_H

#include "Defines.h"

namespace Robot
{
	class Motor;
	class Communication;
	class Controls
	{
	private:
		int buttons[8]; //will hold button presses
		int dpad; //dpad value
		int triggers; //trigger depreciation value
		Motor* motor;
		Communication* comm;
		byte prevACode;
		byte prevPCode;
		byte prevDCode;
		byte prevMCode;
		byte DCode;
		byte PCode;
		byte ACode;
		byte MCode;
	public:
		Controls(Motor& motor);
		void updateControls(char*);
		void display() const;
		void updateDriving();
		void updateActuators();
		void updatePulley();
		void updateDigging();
		void updateSystemMessages();
		void setComm(Communication&);
		int BitReadCombine(unsigned int x_high, unsigned int x_low);
	};
}
#endif
