#ifndef WIFLY_H
#define WIFLY_H

#include "Defines.h"

namespace Robot
{
	class Wifly
	{
	private:
		//char in; //take in input character from wifly output
		//char* output; //records wifly output and preps for sending to labview 
		//int size; //keeps size of output array almost like a quick and dirty vector class with wayyyy less functionality
	public:
		Wifly();
		//void getUart();
		//void getWlan();
		void reboot();
		void setBaudRate(long);
		void setSSID(char*);
		void setPassPhrase(char*);
		void setChannel(int);
		void setExtAntennae(bool);
		//void print();
		//void sendWiflyInfo();
	};
}
#endif