
// Author :BruceTsao 2014.2.27

#include <AccelStepper.h>

#define randomMax  20
#define randomMix  4

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
#define MaxSpeed 200
#define AccSpeed 120
#define SpeedNumber 100
#define PulseWidth 800
AccelStepper stepper1(AccelStepper::FULL4WIRE  ,PinA1 ,PinA2,PinA3,PinA4);
AccelStepper stepper2(AccelStepper::FULL4WIRE  ,PinB1 ,PinB2,PinB3,PinB4);
AccelStepper stepper3(AccelStepper::FULL4WIRE  ,PinC1 ,PinC2,PinC3,PinC4);
int MoveSteps = 4000 ;

int rollpos1 = 0 ,  rollpos2 = 0 ,  rollpos3 = 0 ;
long numberDistance = 45 ;


void setup()
{ 
   Serial.begin(9600);
  Serial1.begin(9600);
  randomSeed(millis());
  // now is set random number
stepper1.setMaxSpeed(MaxSpeed);
stepper1.setAcceleration(AccSpeed);
stepper1.setMinPulseWidth(PulseWidth);
stepper1.moveTo(MoveSteps);
stepper1.setSpeed(SpeedNumber);

//------------
stepper2.setMaxSpeed(MaxSpeed);
stepper2.setAcceleration(AccSpeed);
stepper2.setMinPulseWidth(PulseWidth);
stepper2.moveTo(MoveSteps);
stepper2.setSpeed(AccSpeed);
//------------
stepper3.setMaxSpeed(MaxSpeed);
stepper3.setAcceleration(AccSpeed);
stepper3.setMinPulseWidth(PulseWidth);
stepper3.moveTo(MoveSteps);
stepper3.setSpeed(AccSpeed);
//------------
  
  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
    stepper3.setCurrentPosition(0);
}
void loop()
{
if ( checkRoll() )
  {
         /*
          rollpos1 = getRollingNumber(randomMix, randomMax) ;
          rollpos2 = getRollingNumber(randomMix, randomMax) ;
          rollpos3 = getRollingNumber(randomMix, randomMax) ;
          */
          
          if (Serial1.available())
          {
                readBlueTooth() ;
                
          
                  Serial.print("run 1 is :");
                  Serial.print(rollpos1) ;
                  Serial.print("\n");
                  Serial.print("run 2 is :");
                  Serial.print(rollpos2) ;
                  Serial.print("\n");
                  Serial.print("run 3 is :");
                  Serial.print(rollpos3) ;
                  Serial.print("\n");
                  
                    setRollWheel(rollpos1,rollpos2,rollpos3);
                    delay(3000);
          }
  }
  
  runRollWheel();
}

void readBlueTooth()
{
     int incomingByte = 0;   // for incoming serial data
     incomingByte = Serial1.read();
      if (incomingByte == 0x52)    // ox52 = "R"
        {
          Serial.print("Now incomingByte is :(") ;
          Serial.print(incomingByte) ;
          Serial.print(")\n");
          rollpos1 =  Serial1.parseInt() ;
          rollpos2 =  Serial1.parseInt() ;
          rollpos3 =  Serial1.parseInt() ;
        }
  
}


void setRollWheel(int t1, int t2, int t3)
{
stepper1.move(t1 * numberDistance);
stepper2.move(t2 * numberDistance);
stepper3.move(t3 * numberDistance);

}


void runRollWheel()
{
 if (stepper1.distanceToGo() > 0)
{
  stepper1.run();
  //  stepper1.runSpeed();
}

 if (stepper2.distanceToGo() > 0)
{
    stepper2.run();
  //  stepper2.runSpeed();
}

 if (stepper3.distanceToGo() > 0)
{
    stepper3.run();  
  //  stepper3.runSpeed();
}






}

boolean checkRoll()
{
  boolean tmp = false ;
  if ( (stepper1.distanceToGo() == 0 ) && (stepper2.distanceToGo() == 0 ) && (stepper2.distanceToGo() == 0 ))
      tmp = true ;
    
    return tmp ;  
}

int getRollingNumber(int st1, int st2)
{
  return random(st1,st2) ;
}

