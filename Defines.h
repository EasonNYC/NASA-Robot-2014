/* header file to keep all our constants in one place
planning on moving our includes to this file as well*/

#ifndef DEFINES_H
#define DEFINES_H

/*includes section*/
#include <Arduino.h>

//motor max speeds
#define maxForward 127
#define maxReverse -127

//motor drivers
#define left 1
#define right 2

//motor wheel powers
#define frontRight 0
#define frontLeft 1
#define backRight 2
#define backLeft 3

//motor and actuator addresses
#define frontAddress 128
#define backAddress 129
#define linearActuator 135

//Actuator Pin
#define SyrenPin 6

//Pulley Pin
#define PulleyPin 7

//Actuator Length Pins
#define Actuator1 A8
#define Actuator2 A9


//voltage, current and proximity sensors pins
#define VoltagePin A0
#define CurrentPin1 A1
#define CurrentPin2 A2
#define CurrentPin3 A3
#define CurrentPin4 A4
#define CurrentPin5 A5
#define CurrentPin6 A6 
#define ProximityPin A7

//voltage and current sensors values
#define voltage 0
#define sensor1 1 
#define sensor2 2 
#define sensor3 3 
#define sensor4 4 
#define sensor5 5 

//communications
#define commBegin '$'
#define commEnd '*'
#define commStart '#'



//maximun number of messages that can be sent
#define maxrows 10   
#define maxcols 20

//controller buttons
#define A 0
#define B 1
#define X 2
#define Y 3
#define RB 4
#define LB 5
#define Back 6
#define Start 7

//Ramping Constants
#define DeltaRamp 15

//watchdog,heartbeat,actuator, intervals
#define INTERVALHB 500
#define INTERVALWDT 750
#define INTERVALVOL 1000
#define INTERVALCUR 600
#define INTERVALREBOOT 60000


#endif
