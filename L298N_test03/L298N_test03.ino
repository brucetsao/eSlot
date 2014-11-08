#include <Stepper.h>

int Pin1 = 46; 
int Pin2 = 48; 
int Pin3 = 50; 
int Pin4 = 52; 
int _step = 0; 
int motorSpeed = 60;

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
Stepper stepper(STEPS, Pin1, Pin2, Pin3,Pin4);

// the previous reading from the analog input
int previous = 0;
void initall()
{
  
  Serial.begin(9600);
  Serial.println("program start here ");
  
    pinMode(Pulseinpin,INPUT) ;
     pinMode(SensorLedPin,OUTPUT) ; 

}



void setup()
{

  // set the speed of the motor to 30 RPMs
    initall();
  test() ;
}

void loop()
{
  // get the sensor value


  delay(200);
}

void test()
{
      int i ;
  int sensorValue  ;
  int sum =0 ;
     stepper.setSpeed(motorSpeed);
    for (i=0 ; i < STEPS; i++)
    {
         stepper.step(1) ;
          delayMicroseconds(motordelay);
          sensorValue= digitalRead(Pulseinpin);
         Serial.print(sensorValue);
          Serial.print(","); 
        sum += sensorValue ;

    }
   Serial.print("\n");
   Serial.print("\n");
   Serial.print("run 160 and sum = ");
   Serial.print(sum);

   Serial.print("\n");
} 

