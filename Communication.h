#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "Defines.h"

namespace Robot
{
	class Watchdog;
	class Controls;
	class Communication
	{
	private:
		char input[20]; //array to store input from wifly
		char output[maxrows][maxcols]; //array to store output from arduino
		char in; //Serial3.read character
		unsigned char checksumNumber;
		Watchdog* watchdog;
		Controls* control;
	public:
		Communication(Watchdog& wdt, Controls& controls);
		void recComm();
		void sendComm();
		void clear(char* arr);
		void display(char* arr);
		void addComm(const char ID, const byte length, byte* message, int* mess = NULL);
		byte checkSum(char*, int);
	};
}
#endif
