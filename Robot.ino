#include <SoftwareSerial.h>
#include <SyRenSimplified.h>
#include <Sabertooth.h>
#include "Defines.h"
#include "Watchdog.h"
#include "Communication.h"
#include "Heartbeat.h"
#include "Sensor.h"
#include "Motor.h"
#include "Controls.h"
#include "Alarm.h"
#include "Wifly.h"
#include "Timer.h"
using namespace Robot;

Timer timer;
Wifly wifly;
Motor motor;
Controls control(motor);
Watchdog watchdog(wifly, timer);
Alarms alarm;
Communication comm(watchdog, control);
Heartbeat hb(comm);
Sensor sensors(comm, motor, alarm);

void setup()
{
	Serial.begin(57600);
	Serial2.begin(9600);
	Serial3.begin(115200);
	motor.setSSBegin();
	motor.setSS2Begin();
	watchdog.reset();
	alarm.setComms(comm);
	control.setComm(comm); 
	hb.reset();
}
void loop()
{
	hb.send();
	sensors.send();
	comm.sendComm();
	comm.recComm();
	watchdog.check();
}
