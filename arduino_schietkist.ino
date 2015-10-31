/*
** Get the LCD I2C Library here: https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/LiquidCrystal_V1.2.1.zip
** Mirror: http://www.4tronix.co.uk/arduino/sketches/LiquidCrystal_V1.2.1.zip
*/

#include <RCSwitch.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

RCSwitch mySwitch = RCSwitch();
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int buttonPin = 2; // Set button
boolean currentState = LOW; // Current button state
boolean lastState = LOW; // Last button state

//See man page about unsigned long -- https://www.arduino.cc/en/Reference/UnsignedLong
//Pause time in ms, 1*60*1000 = 60000 = 1 minute
unsigned long pauseOne = 2000; // Set pause time slot 1
unsigned long pauseTwo = 2000; // Set pause time slot 2
unsigned long pauseThree = 2000; // Set pause time slot 3
unsigned long pauseFour = 2000; // Set pause time slot 4
unsigned long pauseFive = 2000; // Set pause time slot 5
unsigned long pauseSix = 2000; // Set pause time slot 6
unsigned long pauseSeven = 2000; // Set pause time slot 7
unsigned long pauseEight = 2000; // Set pause time slot 8
unsigned long pauseNine = 2000; // Set pause time slot 9
unsigned long pauseTen = 2000; // Set pause time slot 10
unsigned long pauseEleven = 2000; // Set pause time slot 11
unsigned long pauseTwelve = 2000; // Set pause time slot 12

void setup() {
  
  // Set Pin as INPUT
  pinMode(buttonPin, INPUT);
    
  // Used to type in characters
  Serial.begin(9600);
  
  // Initialize the lcd for 16 chars 2 lines, turn on backlight
  lcd.begin(16,2);
  
  // Quick 3 blinks of backlight 
    for(int i = 0; i< 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight();

  // Transmitter is connected to Arduino Pin #8
  mySwitch.enableTransmit(8);

  // Optional set pulse length.
  mySwitch.setPulseLength(500);
  
}

void loop() {
currentState = digitalRead(buttonPin);
  if (currentState == LOW && lastState == HIGH)
  {
  lcd.setCursor(1,0);
  lcd.print("Start Countdown");
  lcd.setCursor(0,1);
  lcd.print("1..............");
  delay(1000);

  lcd.setCursor(0,0);
  lcd.print("Start Countdown");
  lcd.setCursor(0,1);
  lcd.print("1...2..........");
  delay(1000);

  lcd.setCursor(0,0);
  lcd.print("Start Countdown");
  lcd.setCursor(0,1);
  lcd.print("1...2...3......");
  delay(1000);

  lcd.setCursor(0,0);
  lcd.print("Start Countdown");
  lcd.setCursor(0,1);
  lcd.print("1...2...3...NOW");
  delay(1000);

  //Slot 1
  mySwitch.send(4019459, 24);
  lcd.setCursor(0,0);
  lcd.print("==== SLOT 1 ====");
  lcd.setCursor(0,1);
  lcd.print("===== FIRE =====");
  delay(pauseOne);

  //Slot 2
  mySwitch.send(4019468, 24);
  lcd.setCursor(0,0);
  lcd.print("==== SLOT 2 ====");
  lcd.setCursor(0,1);
  lcd.print("===== FIRE =====");
  delay(pauseTwo);

  //Slot 3
  mySwitch.send(4019471, 24);
  lcd.setCursor(0,0);
  lcd.print("==== SLOT 3 ====");
  lcd.setCursor(0,1);
  lcd.print("===== FIRE =====");
  delay(pauseThree);

  //Slot 4
  mySwitch.send(4019504, 24);
  lcd.setCursor(0,0);
  lcd.print("==== SLOT 4 ====");
  lcd.setCursor(0,1);
  lcd.print("===== FIRE =====");
  delay(pauseFour);

  //Slot 5
  mySwitch.send(4019507, 24);
  lcd.setCursor(0,0);
  lcd.print("==== SLOT 5 ====");
  lcd.setCursor(0,1);
  lcd.print("===== FIRE =====");
  delay(pauseFive);

  //Slot 6
  mySwitch.send(4019516, 24);
  lcd.setCursor(0,0);
  lcd.print("==== SLOT 6 ====");
  lcd.setCursor(0,1);
  lcd.print("===== FIRE =====");
  delay(pauseSix);

  //Slot 7
  mySwitch.send(4019519, 24);
  lcd.setCursor(0,0);
  lcd.print("==== SLOT 7 ====");
  lcd.setCursor(0,1);
  lcd.print("===== FIRE =====");
  delay(pauseSeven);

  //Slot 8
  mySwitch.send(4019648, 24);
  lcd.setCursor(0,0);
  lcd.print("==== SLOT 8 ====");
  lcd.setCursor(0,1);
  lcd.print("===== FIRE =====");
  delay(pauseEight);
  
  //Slot 9
  mySwitch.send(4019651, 24);
  lcd.setCursor(0,0);
  lcd.print("==== SLOT 9 ====");
  lcd.setCursor(0,1);
  lcd.print("===== FIRE =====");
  delay(pauseNine);

  //Slot 10
  mySwitch.send(4019660, 24);
  lcd.setCursor(0,0);
  lcd.print("==== SLOT 10 ===");
  lcd.setCursor(0,1);
  lcd.print("===== FIRE =====");
  delay(pauseTen);

  //Slot 11
  mySwitch.send(4019663, 24);
  lcd.setCursor(0,0);
  lcd.print("==== SLOT 11 ===");
  lcd.setCursor(0,1);
  lcd.print("===== FIRE =====");
  delay(pauseEleven);

  //Slot 12
  mySwitch.send(4019696, 24);
  lcd.setCursor(0,0);
  lcd.print("==== SLOT 12 ===");
  lcd.setCursor(0,1);
  lcd.print("===== FIRE =====");
  delay(pauseTwelve);
  }
  
  else if(currentState == HIGH && lastState == LOW){
  lcd.setCursor(0,0);
  lcd.print("System Activated");
  lcd.setCursor(0,1);
  lcd.print(" Push to start ");
  delay(1);
  }
  lastState = currentState;
}
