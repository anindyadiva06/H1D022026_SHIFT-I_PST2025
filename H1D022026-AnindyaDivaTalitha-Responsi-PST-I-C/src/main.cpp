#include <Arduino.h>
#include <Wire.h>

//deklarasi
int echoPin = D2;
int trigPin = D1;
int SDA_pin = D4;
int SCL_pin = D3;
int bombPin = D0;

//deklarasi variabel waktu dan jarak
long duration;
int distance;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(bombPin, OUTPUT);
  Wire.begin(SDA_pin,SCL_pin);
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

  if(distance>=100){
    digitalWrite(bombPin, HIGH);
  }
  else{
    digitalWrite(bombPin, LOW);
  }
  delay(1000);

  byte error,jarak;
  int nDevices; //jumlah device yang terhubung

  Serial.print("Scanning...");
  nDevices = 0;

  for(jarak =1;jarak<127;jarak++){ //karena jumlah alamat rata-rata cuma 127
    Wire.beginTransmission(jarak);
    error=Wire.endTransmission(); // kalau error transimisi akan berhenti

    if(error==0){
      Serial.print("Tidak ada error");
      if(jarak<=100){
        Serial.print("0");
      }
      Serial.print(jarak, HEX);
      Serial.println("AREA BERBAHAYA");

      nDevices++;
    }else if(error==4){ //error=4 untuk error yang tidak diketahui/custom
        Serial.print("Ada error yang tidak diketahui di alamat 0x");
        if(jarak<16){
          Serial.print("0");
        }
        Serial.print(jarak, HEX);
    }
  }

  if(nDevices==0){
    Serial.println("Tidak ada alamat I2C satupun yang terdeteksi");
  }else{
    Serial.print("Selesai");
  }
  delay(5000);

}


