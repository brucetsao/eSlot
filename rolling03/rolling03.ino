#include <Stepper.h>
int PinA1 = 22; 
int PinA2 = 24; 
int PinA3 = 26; 
int PinA4 = 28; 
int _step = 0; 
int motorSpeed = 75;

#define Sensorpin A0
#define Pulseinpin 3 
#define Sensorlimit 750
#define SensorLedPin 13
int motordelay = 200 ;
unsigned long duration;


// change this to the number of steps on your motor
#define STEPS 180
#define RUNSTEPS 200
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper1(STEPS, PinA1, PinA2, PinA3,PinA4);

// the previous reading from the analog input
int previous = 0;
void initall()
{
  
  Serial.begin(9600);
  Serial.println("program start here ");
  
    pinMode(Pulseinpin,INPUT) ;
   //  pinMode(SensorLedPin,OUTPUT) ; 
    stepper1.setSpeed(motorSpeed);
}



void setup()
{

  // set the speed of the motor to 30 RPMs
    initall();
  test() ;
  delay(200);
}

void loop()
{
  // get the sensor value


}

void test()
{
    runmotor1(120);
    
} 

void runmotor1(int runsteps)
{
  unsigned long duration;
  int counts = 0 ;
   int sensorValue  ;
  while (counts < runsteps)
  {
       stepper1.step(1) ;
        //  delayMicroseconds(motordelay);
        //  sensorValue= digitalRead(Pulseinpin);     
        duration = pulseIn(Pulseinpin, HIGH);  
         counts ++ ;
               Serial.print(duration);
          Serial.print(","); 
  }
     Serial.print("\n");
   Serial.print("\n");
   Serial.print("run 160 and sum = ");
   Serial.print(counts);

   Serial.print("\n");
}
