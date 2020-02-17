
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <dht11.h>
dht11 DHT11; // create object of DHT11
#define dhtpin A0 // set the pin to connect to DHT11
#define FLAME A1 // connect DO pin of sensor to this pin
//#define ALARM 8 // pin 8 for Alarm
#define leftWheelF  D6
#define leftWheelB  D7
#define rightWheelF  D8
#define rightWheelB D9
#define enableL D5
#define enableR D10
   

void turnOff(){
  digitalWrite(enableL,LOW);
  digitalWrite(enableR,LOW);
  analogWrite(leftWheelF,0);
  analogWrite(leftWheelB,0);
  analogWrite(rightWheelF,0);
  analogWrite(rightWheelB,0);
}
void enable(){
  digitalWrite(enableL,HIGH);
  digitalWrite(enableR,HIGH);
}
void turnRight(){
  turnOff();
  enable();
  analogWrite(leftWheelF,128);
  analogWrite(rightWheelB,128);
  
}
void turnLeft(){
 turnOff();
  enable();
  analogWrite(leftWheelB,128);    
  analogWrite(rightWheelF,128);

}
void moveForward(){
   turnOff();
    enable();
  analogWrite(leftWheelF,128);
  analogWrite(rightWheelF,128);

}
void moveBackward(){
   turnOff();
    enable();
  analogWrite(leftWheelB,128);
  analogWrite(rightWheelB,128);
 
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(D5, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D9, OUTPUT);
  pinMode(D10, OUTPUT);
  pinMode(FLAME, INPUT);//define FLAME input pin

}

// the loop function runs over and over again forever
void loop() {
    flame();
  temperatureHumidity();
 turnLeft();
 delay(1000);
 turnOff();
 turnRight();
 delay(1000);
 moveForward();
 delay(1000);
 moveBackward();
 delay(1000);
 turnOff();
 delay(1000);
  
                       // wait for a second
}

void temperatureHumidity(){
  DHT11.read(dhtpin);
  int humidity = DHT11.humidity;// get humidity

   Serial.print(getTemp('C'));
   Serial.print("C ");
   Serial.print(getTemp('F'));
   Serial.print("F ");
   Serial.print(getTemp('K'));
   Serial.print("K ");
   Serial.print(" humidity:");
   Serial.print (humidity);
   Serial.println("% ");
   Serial.println();

}

float getTemp(char type) {
  float temp = (float)DHT11.temperature;//get temp
  if(type =='F')
  {
    return temp * 1.8 + 32;// convert to fahrenheit
  }else if(type =='K')
  {
    return temp + 274.15;// convert to Kelvin
  }else{
   return temp; 
  }
  
}

void flame(){
  int fire = digitalRead(FLAME);// read FLAME sensor


  if( fire == LOW)
  {
    Serial.println("Fire! Fire!");
  }else{
    Serial.println("Peace");

  }
}
