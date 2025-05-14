#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); // 16=coloumn, 2=row


void setup() {
    Wire.begin(SDA_pin, SCL_pin);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Alamat dari alat tersebut adalah");
    lcd.setCursor(0,1);
    lcd.print("0x27");
}

void loop() {
    lcd.scrollDisplayLeft();
    delay(150);
}
