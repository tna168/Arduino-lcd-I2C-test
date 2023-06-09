#include "I2CScanner.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
I2CScanner scanner;
const uint8_t num_addresses = 4;
const byte addresses[num_addresses] = { 0x27, 0x3F, 0x20, 0x38 };
bool results[num_addresses] = { false, false, false, false};
uint8_t index=0;
int lcdadd=0;
void setup() 
{
	Serial.begin(9600);
	//while (!Serial) {};
	scanner.Init();
 lcd_autoscan();

}

void loop() 
{ 
  LiquidCrystal_I2C lcd(lcdadd,20,4);  // set the LCD address
    
	lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("AMY-1602 TEST");
  lcd.setCursor(3,1);
  lcd.print("ADDRES=0X");
  lcd.print(addresses[index],HEX);
 
  delay(10000);
}

void lcd_autoscan()


{
  for (uint8_t index = 0; index < num_addresses; index++)
  {
    results[index] = scanner.Check(addresses[index]);
  }
  
  for (uint8_t index = 0; index < num_addresses; index++)
  {
    if (results[index])
    {
      Serial.print("Found device ");
      Serial.print(index);
      Serial.print(" at address ");
      Serial.println(addresses[index], HEX);
      lcdadd=(addresses[index]);
         
    }
  }
  delay(500);
   
  }
