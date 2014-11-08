#include <Stepper.h>


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


// change this to the number of steps on your motor
#define STEPS 180 
#define RUNSTEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper1(STEPS, PinA1, PinA2, PinA3,PinA4);
Stepper stepper2(STEPS, PinB1, PinB2, PinB3,PinB4);
Stepper stepper3(STEPS, PinC1, PinC2, PinC3,PinC4);

// the previous reading from the analog input
int previous = 0;

void setup()
{
  // set the speed of the motor to 30 RPMs
  stepper1.setSpeed(motorSpeed);
  stepper2.setSpeed(motorSpeed);
  stepper3.setSpeed(motorSpeed);
}

void loop()
{
  // get the sensor value
 stepper1.step(2) ;
 stepper2.step(2) ;
 stepper3.step(2) ;

}

