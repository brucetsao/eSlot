#include <Stepper.h>
#define randomMax  8
#define randomMix  1
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


// change this to the number of steps on your motor
#define STEPS 180 
#define RUNSTEPS 200

int rollpos1 = 0 ,  rollpos2 = 0 ,  rollpos3 = 0 ;
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
  Serial.begin(9600);
  randomSeed(millis());
  // set the speed of the motor to 30 RPMs
  stepper1.setSpeed(motorSpeed);
  stepper2.setSpeed(motorSpeed);
  stepper3.setSpeed(motorSpeed);
  rollpos1 = getRollingNumber(randomMix, randomMax) ;
  rollpos2 = getRollingNumber(randomMix, randomMax) ;
  rollpos3 = getRollingNumber(randomMix, randomMax) ;
  Serial.print("run 1 is :");
  Serial.print(rollpos1) ;
  Serial.print("\n");
  Serial.print("run 2 is :");
  Serial.print(rollpos2) ;
  Serial.print("\n");
  Serial.print("run 3 is :");
  Serial.print(rollpos3) ;
  Serial.print("\n");
  
}

void loop()
{
  // get the sensor value
 runRollWheel(&rollpos1,&rollpos2, &rollpos3) ;
 

}


int runRollWheel(int *b1, int *b2, int *b3)
{
  if (*b1 >0 )
    {
       stepper1.step(numberDistance) ;
      *b1 --  ;
    } 
  if (*b2 >0 )
    {
       stepper2.step(numberDistance) ;
      *b2 --  ;
    } 
  
  if (*b3 >0 )
    {
       stepper3.step(numberDistance) ;
      *b3 --  ;
    } 
  
  Serial.print("debug inner var:(");
  Serial.print(*b1);
  Serial.print("/");
  Serial.print(*b2);
  Serial.print("/");
  Serial.print(*b3);
  Serial.print(")\");
  
  
  
 return ( (*b1 >0) | (*b2 >0) |(*b3 >0) ) ;
}


int getRollingNumber(int st1, int st2)
{
  return random(st1,st2) ;
}



