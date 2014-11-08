
// Author :BruceTsao 2014.3.6

#include <Stepper.h>
  

#define EnablePin1 8      // output pin to control Pulse
#define ClockPin1 9      // output pin to control Pulse
#define CWPin1 10        // Control Motor direcsetSpeedtion : Clcokwise or CounterClockwise

//----------------------


int RunSpeed =  300 ;   //  speed of motor
int  PulseWidth = 800  ;  // pulse width for each pulse
int microsteps = 2;
int revolution = 160;
double  ratio = 2;
int Motor1direction = 1 ;
int rundelay = 200 ;


Stepper stepper1(revolution * microsteps  ,ClockPin1 ,CWPin1);
   

int MoveSteps = 400000 ;
unsigned int data = 0;  

double motor1ratio = 0.001 ;


void setup()
{ 
  
initall();
initcontroller();


}
void loop()
{
  

    //  motor1steps(calculatePulse(3,motor1ratio),1) ;
                                 // Display the returned numeric value
   motor1steps(2000, 1);
   delay(50);
    
    
}
void initall()
{
  pinMode(EnablePin1,OUTPUT) ;
    pinMode(ClockPin1,OUTPUT) ;
  pinMode(CWPin1,OUTPUT) ;
digitalWrite(EnablePin1,HIGH) ;

  
  Serial.begin(9600);
  
}
void initcontroller()
{
// motor1 init
stepper1.setSpeed(RunSpeed);    // set Max Speed of Motor




Serial.println(RunSpeed);
//stepper1.runSpeed();

}


void motor1steps(int motorspd, int dirw)
{
  int counter = 0 ;
    if (dirw == 1) {
          digitalWrite(CWPin1, HIGH);
    }
    else {
          digitalWrite(CWPin1, LOW);
    }

for(counter = 0 ; counter <motorspd; counter ++)
{
    digitalWrite(ClockPin1, HIGH);
  delayMicroseconds(PulseWidth);
  digitalWrite(ClockPin1, LOW);
  delayMicroseconds(PulseWidth);
}
}

int calculatePulse(int mm, double ratios )
{
  
  return (int)((double)mm * ratios * revolution * microsteps) ;
  
}
