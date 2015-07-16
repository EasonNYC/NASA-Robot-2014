#include "Wifly.h"

namespace Robot
{
	Wifly::Wifly() //initialize output array to always hold its first char as the message id denoted as a tilde / sets the size to 1 after ID char
	{}
	void Wifly::reboot() //reboots wifly will be used when changing the ext antenna and/or if ghost connection is present
	{
		char* arr = "$$$";
		char* string = strcat(arr, "\0");
		int i = 0;
		while (arr[i] != '\0')
		{
			Serial3.write(arr[i]);
			++i;
			delay(250);
		}

		Serial3.write("reboot\r");
	}
	void Wifly::setBaudRate(long baudrate) //takes in a number its long incase number is ex. 115200 converts it to a string and prints the string piece by piece to the wifly
	{
		char* arr = "$$$";
		char* string = strcat(arr, "\0");
		int i = 0;
		while (arr[i] != '\0')
		{
			Serial3.write(arr[i]);
			++i;
			delay(250);
		}

		Serial3.write("set uart b ");
		String num(baudrate);
		for (int i = 0; i < num.length(); i++)
		{
			Serial3.write(num[i]);
		}
		Serial3.write("\r");

		Serial3.write("save\r");

		Serial3.write("exit\r");

	}
	void Wifly::setChannel(int channel)
	{
		char* arr = "$$$";
		char* string = strcat(arr, "\0");
		int i = 0;
		while (arr[i] != '\0')
		{
			Serial3.write(arr[i]);
			++i;
			delay(250);
		}

		Serial3.write("set wlan channel ");
		String num(channel);
		for (int i = 0; i < num.length(); i++)
		{
			Serial3.write(num[i]);
		}
		Serial3.write("\r");

		Serial3.write("save\r");

		Serial3.write("exit\r");

	}
	void Wifly::setSSID(char* ssid)
	{
		char* arr = "$$$";
		char* string = strcat(arr, "\0");
		int i = 0;
		while (arr[i] != '\0')
		{
			Serial3.write(arr[i]);
			++i;
			delay(250);
		}
		Serial3.write("set wlan ssid ");
		Serial3.write(ssid);
		Serial3.write("\r");
		Serial3.write("save\r");
		Serial3.write("exit\r");
	}
	void Wifly::setPassPhrase(char* pass)
	{
		char* arr = "$$$";
		char* string = strcat(arr, "\0");
		int i = 0;
		while (arr[i] != '\0')
		{
			Serial3.write(arr[i]);
			++i;
			delay(250);
		}

		Serial3.write("set wlan phrase ");
		Serial3.write(pass);
		Serial3.write("\r");

		Serial3.write("save\r");

		Serial3.write("exit\r");

	}
	void Wifly::setExtAntennae(bool antennae) //in wifly gsx manuel 0 or false to use wifly own chip antenna or 1 for and ext antenna
	{
		char* arr = "$$$";
		char* string = strcat(arr, "\0");
		int i = 0;
		while (arr[i] != '\0')
		{
			Serial3.write(arr[i]);
			++i;
			delay(250);
		}
		Serial3.write("set wlan ext_antenna ");
		Serial3.write(antennae);
		Serial3.write("\r");
		Serial3.write("save\r");
		Serial3.write("reboot\r");
	}
	/*void Wifly::print() //on every iteration of print it records each char sent by the wifly and adds it to the output buffer as well as prints to serial monitor. after debug finish will delete print to serial monitor part
	{
	while (Serial3.available() > 0)
	{
	this->in = Serial3.read();
	Serial.print(in);
	//output[this->size] = in;
	//this->size++;
	}
	//Serial.println();
	}*/
	/*void Wifly::getWlan() //gets wifly wlan info ssid, passphrase, etc....
	{
	char* arr = "$$$";
	char* string = strcat(arr, "\0");
	int i = 0;
	while (arr[i] != '\0')
	{
	Serial3.write(arr[i]);
	++i;
	delay(250);
	}

	Serial3.write("get wlan\r");
	delay(100);

	Serial3.write("exit\r");

	}*/
	/*void Wifly::getUart() //gets wifly uart settings basically all we care about here is the baudrate
	{
	char* arr = "$$$";
	char* string = strcat(arr, "\0");
	int i = 0;
	while (arr[i] != '\0')
	{
	Serial3.write(arr[i]);
	++i;
	delay(250);
	}

	Serial3.write("get uart\r");
	delay(100);

	Serial3.write("exit\r");

	}*/
	/*void Wifly::sendWiflyInfo() //gets uart and wlan info and write the output buffer to wifly then resets size to 1 never clearing the ID :D
	{
	this->getUart();
	delay(250);
	this->getWlan();
	delay(250);
	for (int i = 0; i < this->size; i++)
	{
	Serial.print(output[i]);
	//Serial3.write(output[i]);
	}
	this->size = 1;
	}*/
}