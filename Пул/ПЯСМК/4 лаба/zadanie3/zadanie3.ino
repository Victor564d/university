#include <Wire.h>
#include "DHT.h"
#define DHTPIN 4 // номер цифрового вывода,
//к которому подключен сигнальный вывод датчика
DHT dht(DHTPIN, DHT11);
#include "LCD_1602_RUS.h" // подключаем библиотеку LCD_1602_RUS

LCD_1602_RUS lcd(0x27,16,2);
void setup()
{ lcd.init(); lcd.backlight();  dht.begin();
}
void loop()
{
  lcd.clear(); lcd.setCursor(0,0);
  float h = dht.readHumidity(); // измеряем влажность
  float t = dht.readTemperature();
  // измеряем температуру
  if (isnan(h) || isnan(t)) { // проверка чтения дан-ных
    lcd.print("Ошибка"); lcd.setCursor(0,1); lcd.print("считывания");
    delay(100);
    return;
  } lcd.print("Влажность:");
  lcd.print(h,1);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Тем-тура:");
  lcd.print(t); lcd.print("*C"); //Вывод показаний на экран
  delay(1000);

}
