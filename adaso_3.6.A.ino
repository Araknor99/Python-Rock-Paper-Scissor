#define dw digitalWrite
int RichtungA = 12;
int RichtungB = 13;
int pwmA = 3;
int pwmB = 11;
int bremseA = 8;
int bremseB = 9;
int geschwindigkeit = 255;
int geschwindigkeit2 = 251;
int rechtsA = 255;
int rechtsB = 230;
int LinksA = 235;
int LinksB = 251;
int sensor = 2;
int grenze = 350;
/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  pinMode(RichtungA,OUTPUT);
  pinMode(RichtungB,OUTPUT);
  pinMode(bremseA,OUTPUT);
  pinMode(bremseB,OUTPUT);
  analogWrite(pwmA,geschwindigkeit2);
  analogWrite(pwmB,geschwindigkeit);
  digitalWrite(bremseA,HIGH);
  digitalWrite(bremseB,HIGH);
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
} 
 
void loop() 
{ 
  for(pos = 51; pos <= 145; pos += 1) // goes from 0 degrees to 180 degrees 
  {      // in steps of 1 degree
    int sensorValue = analogRead(A2); 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);    // waits 15ms for the servo to reach the position
    Serial.println(sensorValue);
    if (sensorValue < grenze)
    { 
      dw(bremseA,LOW);
      dw(bremseB,LOW);
      dw(RichtungA,HIGH);
      dw(RichtungB,HIGH);
      }else{   
    dw(RichtungB,LOW);
    dw(bremseB,HIGH);
    dw(RichtungA,LOW);
    dw(bremseA,HIGH);
    myservo.write(155);
    delay(1000);
    int sensorValue = analogRead(A2);
    if(sensorValue < grenze){
      dw(bremseA,LOW);
      dw(bremseB,LOW);
      dw(RichtungA,LOW);
      dw(RichtungB,HIGH);
      delay(250);
      dw(bremseA,HIGH);
      dw(bremseB,HIGH);
      dw(RichtungA,LOW);
      dw(RichtungB,LOW);
      }else{
        myservo.write(41);
        delay(1000);
        int sensorValue = analogRead(A2);
        if(sensorValue < grenze){
        dw(bremseA,LOW);
        dw(bremseB,LOW);
        dw(RichtungA,HIGH);
        dw(RichtungB,LOW);
        delay(250);
        }else{  
        dw(bremseA,LOW);
        dw(bremseB,LOW);
        dw(RichtungA,LOW);
        dw(RichtungB,LOW);
        delay(2000);
        myservo.write(155);
        delay(1000);
        int sensorValue = analogRead(A2);
        if (sensorValue < grenze){
         dw(bremseA,LOW);
         dw(bremseB,LOW);
         dw(RichtungA,LOW);
         dw(RichtungB,HIGH);
         delay(250);
         }else{
          myservo.write(41);
          delay(1000);
          int sensorValue = analogRead(A2);
          if (sensorValue < grenze){
            dw(bremseA,LOW);
            dw(bremseB,LOW);
            dw(RichtungA,HIGH);
            dw(RichtungB,LOW);
            }else{
              dw(bremseA,LOW);
              dw(bremseB,LOW);
              dw(RichtungA,LOW);
              dw(RichtungB,HIGH);
              }
          } 
        }
        }
    }
    delay(10);
  } 
  for(pos = 145; pos>=51; pos-=1)     // goes from 180 degrees to 0 degrees 
  { 
    int sensorValue = analogRead(A2);    
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);    // waits 15ms for the servo to reach the position
    Serial.println(sensorValue);
    if (sensorValue < grenze){
      dw(bremseA,LOW);
      dw(bremseB,LOW);
      dw(RichtungA,HIGH);
      dw(RichtungB,HIGH);
      }else{   
    dw(RichtungB,LOW);
    dw(bremseB,HIGH);
    dw(RichtungA,LOW);
    dw(bremseA,HIGH);
    myservo.write(41);
    delay(1000);    
    int sensorValue = analogRead(A2);
    if (sensorValue < grenze ){
      dw(bremseA, LOW);
      dw(bremseB, LOW);
      dw(RichtungA, HIGH);
      dw(RichtungB, LOW);
      delay(250);
      dw(RichtungB,LOW);
      dw(RichtungA,LOW);
      dw(bremseA,HIGH);
      dw(bremseB,HIGH);
    }else{
      myservo.write(155);
      delay(1000);
      int sensorValue = analogRead(A2);
      if(sensorValue < grenze){
        dw(bremseA,LOW);
        dw(bremseB,LOW);
        dw(RichtungA,LOW);
        dw(RichtungB,HIGH);
        delay(250);
        }else{
      dw(RichtungB,LOW);
      dw(RichtungA,LOW);
      dw(bremseA,LOW);
      dw(bremseB,LOW);
      delay(2000);
      }
      }
    delay(10);
 
  }
  }

  
  //delay(2000);
  //digitalWrite(RichtungA,HIGH);
  //digitalWrite(RichtungB,HIGH);
  //digitalWrite(bremseA,LOW);
  //digitalWrite(bremseB,LOW);
  //delay(10000);
  //dw(bremseA,HIGH);
  //dw(bremseB,HIGH);
  //delay(2000);
  //dw(bremseA,LOW);
  //dw(bremseB,LOW);
  //dw(RichtungA,LOW);
  //dw(RichtungB,LOW);
  //delay(10000);
  //dw(bremseA,HIGH);
  //dw(bremseB,HIGH);
  //delay(2000);
  
  
} 


