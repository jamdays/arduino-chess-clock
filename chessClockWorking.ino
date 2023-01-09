#include <LiquidCrystal.h>
LiquidCrystal lcd(3, 4, 5, 6, 7, 8);
unsigned long timeOne = 600000;
unsigned long timeTwo = 600000;
bool turnOne = true;
const int switchPin = 13;
unsigned long save = 0; //when the button was pressed
void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  lcd.begin(16, 2);
  lcd.print(timeOne);
  lcd.setCursor(0, 1);
  lcd.print(timeTwo);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //save-- when the button was pressed
  if(digitalRead(switchPin) == HIGH){
    if(turnOne){
      timeOne = timeOne - millis() + save;
    } else{
      timeTwo = timeTwo - millis() + save;
    }
    turnOne = !turnOne;
    save = millis();
  }
  unsigned long time; 
  if(turnOne){
    time = timeOne - millis() + save; 
    lcd.begin(16, 2); 
    unsigned long secs = time % 60000;
    unsigned long mins = time / 60000;
    lcd.print(mins);
    lcd.print(":");
    lcd.print(secs);
    //line two
    lcd.setCursor(0, 1);
    secs = timeTwo % 60000;
    mins = timeTwo / 60000;
    lcd.print(mins);
    lcd.print(":");
    lcd.print(secs);
  } else{
    time = timeTwo - millis() + save;
    lcd.begin(16, 2); 
    unsigned long secs = timeOne % 60000;
    unsigned long mins = timeOne / 60000;
    lcd.print(mins);
    lcd.print(":");
    lcd.print(secs);
    //line two
    lcd.setCursor(0, 1);
    secs = time % 60000;
    mins = time / 60000;
    lcd.print(mins);
    lcd.print(":");
    lcd.print(secs);
  }
  delay(100);

}
