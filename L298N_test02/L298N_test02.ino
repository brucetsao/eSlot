#include <Stepper.h>

int Pin1 = 46; 
int Pin2 = 48; 
int Pin3 = 50; 
int Pin4 = 52; 
int _step = 0; 
int motorSpeed = 4000;

#define Sensorpin A0
#define pulseinpin 3 
#define Sensorlimit 750
#define SensorLedPin 13

unsigned long duration;


// change this to the number of steps on your motor
#define STEPS 160

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
  
    pinMode(pulseinpin,INPUT) ;
     pinMode(SensorLedPin,OUTPUT) ; 

}



void setup()
{
    int i ;
  int sensorValue  ;
  int sum :=0 ;
  // set the speed of the motor to 30 RPMs
    initall();
    stepper.setSpeed(100);
    for (i=0 ; i < 160; i++)
    {
         stepper.step(1) ;
        sensorValue= digitalRead(Sensorpin);
        sum += sensorValue ;
    }
   Serial.print("run 160 and sum = ");
   Serial.print(sum);

   Serial.print("\n");
}

void loop()
{
  // get the sensor value
  
  duration = pulseIn(pulseinpin, HIGH);
  // print out the value you read:
 
  
}

