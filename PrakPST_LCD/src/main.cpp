#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

int SDA_pin = D4;
int SCL_pin = D2;

LiquidCrystal_I2C lcd(0x27,16,2); // 16=coloumn, 2=row


void setup() {
    Wire.begin(SDA_pin, SCL_pin);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Halooo!");
    lcd.setCursor(0,1);
    lcd.print("hyy maniez");
}

void loop() {
    lcd.scrollDisplayLeft();
    delay(150);
}


