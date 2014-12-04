
// Author :BruceTsao 2014.2.27

#include <AccelStepper.h>

#define randomMax  20
#define randomMix  4
#define numberDistance 30

int PinA1 = 22; 
int PinA2 = 24; 
int PinA3 = 26; 
int PinA4 = 28; 
int PinB1 = 30; 
int PinB2 = 32; 
int PinB3 = 34; 
int PinB4 = 36; 
int PinC1 = 38; 
int PinC2 = 40; 
int PinC3 = 42; 
int PinC4 = 44; 
int _step = 0; 
int motorSpeed = 75;


#define ClockPin 9
#define CWPin 10
#define MaxSpeed 400
#define AccSpeed 250
#define PulseWidth 800
AccelStepper stepper1(AccelStepper::FULL4WIRE  ,PinA1 ,PinA2,PinA3,PinA4);
AccelStepper stepper2(AccelStepper::FULL4WIRE  ,PinB1 ,PinB2,PinB3,PinB4);
AccelStepper stepper3(AccelStepper::FULL4WIRE  ,PinC1 ,PinC2,PinC3,PinC4);
int MoveSteps = 4000 ;
void setup()
{ 
stepper1.setMaxSpeed(MaxSpeed);
stepper1.setAcceleration(AccSpeed);
stepper1.setMinPulseWidth(PulseWidth);
stepper1.moveTo(MoveSteps);
//------------
stepper2.setMaxSpeed(MaxSpeed);
stepper2.setAcceleration(AccSpeed);
stepper2.setMinPulseWidth(PulseWidth);
stepper2.moveTo(MoveSteps);
//------------
stepper3.setMaxSpeed(MaxSpeed);
stepper3.setAcceleration(AccSpeed);
stepper3.setMinPulseWidth(PulseWidth);
stepper3.moveTo(MoveSteps);
//------------


}
void loop()
{
// Change direction at the limits
if (stepper1.distanceToGo() == 0)
stepper1.moveTo(-stepper1.currentPosition());
stepper1.run();

if (stepper2.distanceToGo() == 0)
stepper2.moveTo(-stepper1.currentPosition());
stepper2.run();


if (stepper3.distanceToGo() == 0)
stepper3.moveTo(-stepper1.currentPosition());
stepper3.run();


}


