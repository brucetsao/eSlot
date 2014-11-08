#include <Stepper.h>


int PinA1 = 22; 
int PinA2 = 24; 
int PinA3 = 26; 
int PinA4 = 28; 
int _step = 0; 
int motorSpeed = 4000;


// change this to the number of steps on your motor
#define STEPS 100
#define RUNSTEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, PinA1, PinA2, PinA3,PinA4);

// the previous reading from the analog input
int previous = 0;

void setup()
{
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(100);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.avaitable())
  // get the sensor value
 stepper.step(STEPS) ;
 delay(5000);
}

