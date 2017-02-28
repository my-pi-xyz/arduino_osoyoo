#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  // Set up serial communication so we can tell the user what we're doing...
  Serial.begin(9600);
  Serial.print("Program starting...\n");

  // Setup the display object
  lcd.init();
  lcd.backlight();
}

void loop() {
  //----------------------------------------------------------------------------------
  Serial.print("Scrolling text...\n");

  lcd.print("Hello, world!");
    
  // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(300);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(300);
  }

  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(300);
  }

  // delay at the end of the full loop:
  delay(5000);
  lcd.clear();
  lcd.print("Hello, world!");
  
  //----------------------------------------------------------------------------------
  Serial.print("Blinking text...\n");
  
  lcd.blink();
  delay(5000);
  lcd.noBlink();
  delay(5000);
  
  //----------------------------------------------------------------------------------
  Serial.print("Display On/Off...\n");
  lcd.noDisplay();
  delay(5000);
  lcd.display();
  delay(5000);

  lcd.clear();
  lcd.print("Hello, world!");
}
