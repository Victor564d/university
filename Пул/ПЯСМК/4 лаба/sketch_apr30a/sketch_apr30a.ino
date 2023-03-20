

// include the library code:
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2);

byte P[] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B00000
};

byte I[] = {
  B10001,
  B10001,
  B10001,
  B10001,
  B11101,
  B10101,
  B11101,
  B00000
};

byte iii[] = {
  B10101,
  B10101,
  B10101,
  B10101,
  B10101,
  B10101,
  B11111,
  B00000
};

byte G[] = {
  B11111,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B00000
};


byte B[] = {
  B11111,
  B10000,
  B10000,
  B11111,
  B10001,
  B10001,
  B11111,
  B00000
};

byte U[] = {
  B10001,
  B10001,
  B10011,
  B10101,
  B10101,
  B10101,
  B11001,
  B00000
};



void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, P);
  lcd.createChar(1, I);
  lcd.createChar(2, iii);
  lcd.createChar(3, G);
  lcd.createChar(4, B);
  lcd.createChar(5, U);
 
 lcd.setCursor(0, 0);
  for (int i = 0;i<=2 ;i++){
  lcd.write(byte(i)); }
  lcd.print("HO"); 
  lcd.write(byte(3));
  lcd.print("Y"); 
  lcd.write(byte(4));
  lcd.setCursor(0, 1);
  lcd.print("B");
  lcd.write(byte(5));
  lcd.print("KTOP");
  }


void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
 // lcd.setCursor(0, 1);
  // print the number of seconds since reset:
 // lcd.print(millis() / 1000);
  // delay a bit
  //delay(50);
}
 
