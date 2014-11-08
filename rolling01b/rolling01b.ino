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
  int cc ;
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(100);
  Serial.begin(9600);
  for (cc=90; cc <200; cc++)
    {
      Serial.print("now run ");
      Serial.print(cc);
      Serial.print("\n");
    
          crtstepper(cc) ;
      delay(2000);
    }
    
}

void loop()
{
 
}


void crtstepper(int pp)
{
  
  Stepper tmp(pp, PinA1, PinA2, PinA3,PinA4);
  tmp.setSpeed(100);
  tmp.step(pp);
  
}
