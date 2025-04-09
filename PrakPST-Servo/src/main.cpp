#include <Arduino.h>
#include <Servo.h>

Servo myservo;


void setup() {
 myservo.attach(D1);
}

void loop() {
  // for(int position = 0; position<=180; position++){ //bergerak searah jarum jam
  //   myservo.write(position);
  //   delay(10); 
  // }
  // for(int position=180; position>=0; position--){ //bergerak berlawanan arah jarum jam
  //   myservo.write(position);
  //   delay(10);
  // }

  myservo.write(100);
  delay(2000);
  myservo.write(0);
  delay(2000);
  myservo.write(100);
  delay(2000);
}

