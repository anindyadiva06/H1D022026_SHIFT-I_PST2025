#include <Arduino.h>
#include <Wire.h>

int SDA_pin = D4;
int SCL_pin = D2;


void setup() {
  Wire.begin(SDA_pin,SCL_pin);
  Serial.begin(9600);

}

void loop() {
  byte error,address;
  int nDevices; //jumlah device yang terhubung

  Serial.print("Scanning...");
  nDevices = 0;

  for(address =1;address<127;address++){ //karena jumlah alamat rata-rata cuma 127
    Wire.beginTransmission(address);
    error=Wire.endTransmission(); // kalau error transimisi akan berhenti

    if(error==0){
      Serial.print("I2C terbaca pada alamat 0x");
      if(address<16){
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("...!");

      nDevices++;
    }else if(error==4){ //error=4 untuk error yang tidak diketahui/custom
        Serial.print("Ada error yang tidak diketahui di alamat 0x");
        if(address<16){
          Serial.print("0");
        }
        Serial.print(address, HEX);
    }
  }

  if(nDevices==0){
    Serial.println("Tidak ada alamat I2C satupun yang terdeteksi");
  }else{
    Serial.print("Selesai");
  }
delay(5000);

}

