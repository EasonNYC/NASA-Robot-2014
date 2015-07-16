#include "Watchdog.h"
//#include "Alarm.h"
#include "Controls.h"
#include "Communication.h"

namespace Robot
{
	Communication::Communication(Watchdog& wdt, Controls& control /*, Alarms& alarms*/)
		:watchdog(&wdt), control(&control) //, alarm(&alarms)
	{}
	void Communication::clear(char* arr) //used to reset (input or output) arrays to zero. should we use NULL instead of zero?
	{
		for (int i = 0; i < 20; i++)
			arr[i] = 0;
	}

	//add a message to the cue (byte version)
	void Communication::addComm(const char ID, const byte length, byte* message, int* mess)
	{
		if (length >(maxcols - 3)){
			//alert
			//return from function? or increase length?
		}

		//look for first empty row
		for (int i = 0; i < maxrows; i++){
			if (output[i][0] != '#')
			{ //if this is a clear row
				output[i][0] = '#'; //this row now has a message
				output[i][1] = length + 1; //length plus id is the total message length
				output[i][2] = ID; //store the id
				if (message != NULL)
				{
					for (int x = 0; x < length; x++){ //start at just past id and store rest of message
						output[i][x + 3] = message[x];
					}
				}
				else
				{
					for (int x = 0, y = 0; x < (length / 2); x++, y += 2)
					{
						output[i][y + 3] = highByte(mess[x]);
						output[i][y + 4] = lowByte(mess[x]);
					}
				}
				//this->display(output[i]);
				break; //important to break here
			}
		}
	}
	void Communication::display(char* arr) //will display input and output buffers for debug purposes
	{
		for (int i = 0; i < 20; i++)
		{
			Serial.print(arr[i]);
			Serial.print(", ");
		}
		Serial.println(" ");
	}
	//function for receiving incoming messages from labview. returns a pointer to the message.
	void Communication::recComm()
	{
		if (Serial3.available()) //if wifly sent something
		{
			watchdog->reset(); //we're connected so reset the watchdog
			this->in = Serial3.read(); //get 1 byte

			if (this->in == commBegin) //if this is the start of a valid message. all communications from labview begin with '$' (defined as commBegin)
			{
				int x = 0;
				for (int i = 0; ((this->in != commEnd) && (i < maxcols)); i++)
				{
					delay(1); //will be removed once baud rate on arduino and wifly is up'd
					this->in = Serial3.read(); //read next incoming byte
					input[i] = this->in; //store it. these 2 lines can probably be combined
					x++;
				}
				this->checksumNumber = input[x - 2];
				Serial.println();
				//Serial << this->checksumNumber << " " << this->checkSum(input, x) << endl;
			}
			//alarm->ack(input);
			control->updateControls(input);
			this->display(input); //for debug
			this->clear(input);
		}
	}
	byte Communication::checkSum(char* arr, int end)
	{
		byte CRC;
		for (int i = 0; i < end - 2; i++)
			CRC = CRC ^ arr[i];
		return CRC;
	}
	//send out all messages in the outgoing message cue
	void Communication::sendComm()
	{
		for (int i = 0; output[i][0] == commStart; i++) //will write to serial3 only the non empty arrays
		{
			//this->display(output[i]);
			int length = byte(output[i][1]); //temp variable to store the length of the payload
			for (int x = 0; x < length; x++)
				Serial3.write(output[i][x + 2]); //ignore the first 2 bytes(not used by labview), and send everything afterwords.		
			this->clear(output[i]); //finish by clearing that message after it has been sent
		}
	}

}
