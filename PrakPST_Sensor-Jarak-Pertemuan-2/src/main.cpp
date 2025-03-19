#include <Arduino.h>

//deklarasi
int echoPin = D1;
int trigPin = D2;
int ledyellowPin = D3;
int ledredPin = D6;

//deklarasi variabel waktu dan jarak
long duration;
int distance;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledyellowPin, OUTPUT);
  pinMode(ledredPin, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //Untuk menghitung waktu sinyal diterima
  duration = pulseIn(echoPin, HIGH); 

  //Menghitung jarak
  distance = duration * 0.034 / 2; //didapat dari kecepatan= 343m/s yang diubah ke m/microsecond

  //Display serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  if(distance>=10){
    digitalWrite(ledyellowPin, HIGH);
    digitalWrite(ledredPin, HIGH);
  }
  else{
    digitalWrite(ledyellowPin, LOW);
    digitalWrite(ledredPin, LOW);
  }
  delay(1000);
}


