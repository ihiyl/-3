#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 

#define PIN_TRIG 12
#define PIN_ECHO 11
#define MAX_DISTANCE 200 
NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);

LiquidCrystal_I2C lcd(0x27,16,2); 

int button = 0;

void setup()
{
  pinMode(4, INPUT_PULLUP);
  
  lcd.init();                      // Инициализация дисплея  
  lcd.backlight();                 // Подключение подсветки
  //lcd.setCursor(0,0);              // Установка курсора в начало первой строки
  // lcd.print();                     // Набор текста на первой строке
  // lcd.setCursor(0,1);              // Установка курсора в начало второй строки
  // lcd.print();                     // Набор текста на второй строке
}
void loop()
{
  delay(50);
  button = digitalRead(4);

  unsigned int distance = sonar.ping_cm();

  if(button == HIGH)
  {
    lcd.setCursor(0,0); 
    lcd.print("Distantion");
    lcd.setCursor(0,1);              
    lcd.print(distance + "cm"); 
  }
}
