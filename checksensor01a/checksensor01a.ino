#define Sensorpin 3
#define Sensoranalogpin A0
#define Sensorlimit 750
#define SensorLedPin 13


void initall()
{
  
  Serial.begin(9600);
  Serial.println("program start here ");
  
    pinMode(SensorLedPin,OUTPUT) ;
     pinMode(Sensorpin,INPUT) ; 

}
 void setup()
 {

  initall();
 }

 void loop()
 {
 //  int sensorValue = digitalRead(Sensorpin);
   int sensorValue = analogRead(Sensoranalogpin);
  // print out the value you read:
  if (sensorValue == 1)
      {
        digitalWrite(SensorLedPin,HIGH) ;
      }
      else
       {
        digitalWrite(SensorLedPin,LOW) ;
      }     
  Serial.println(sensorValue);
  delay(200) ;
 }


