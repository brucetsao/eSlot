#define Sensorpin A0
#define pulseinpin 3 
#define Sensorlimit 750
#define SensorLedPin 13

unsigned long duration;

void initall()
{
  
  Serial.begin(9600);
  Serial.println("program start here ");
  
    pinMode(pulseinpin,INPUT) ;
     pinMode(SensorLedPin,OUTPUT) ; 

}
 void setup()
 {

  initall();
 }

 void loop()
 {
   int sensorValue = analogRead(Sensorpin);
  duration = pulseIn(pulseinpin, HIGH);
  // print out the value you read:
  Serial.println(duration);
 // delay(80) ;
 }


