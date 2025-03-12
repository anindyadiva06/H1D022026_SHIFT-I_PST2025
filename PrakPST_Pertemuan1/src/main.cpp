#include <Arduino.h>

int LED1 = D0; //disesuain sama letak penempatan lampunya di breadboard (di pin digital mana)
int LED2 = D3; //disesuain sama letak penempatan lampunya di breadboard (di pin digital mana)
int LED3 = D6; //disesuain sama letak penempatan lampunya di breadboard (di pin digital mana)


void setup() { //
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH); // high=true
  delay(5000); // menyala selama 5 detik (satuan dalam milisecond)
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH); 
  delay(3000); 
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH); 
  delay(2000); 
  digitalWrite(LED3, LOW);
}

