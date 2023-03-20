#include <Wire.h> // библиотека для управления устройствами по I2C 
#include "LCD_1602_RUS.h" // подключаем библиотеку LCD_1602_RUS

LCD_1602_RUS LCD(0x27,16,2); // присваиваем имя LCD для дисплея

void setup() {
   LCD.init(); // инициализация LCD дисплея
   LCD.backlight(); // включение подсветки дисплея
   
   LCD.setCursor(0,0); // ставим курсор на 3 символ первой строки
   LCD.print("ПЫШНОГУБ"); // печатаем символ на первой строке
   LCD.setCursor(0,1); // ставим курсор на 3 символ первой строки
   LCD.print("ВИКТОР"); // печатаем символ на первой строке
   LCD.display();
}

void loop() {
  
 LCD.scrollDisplayLeft();
 delay(200);
}
