/*
 * Schematic:
 Plug SIG into A0
 PWR to 3.3V
 GND to GND
  
 * HEY! 
 If you're not currently getting a reading from the Soil Moisture sensor,
 disconnect it from the power source.
 The sensor's conductor can corrode quickly over time if 
 continuously plugged into power and exposed to moisture.

 *Callibration
 The Soil Moisture sensor produces an analog value --
 an electrical reading that increases with exposure to moisture.
 There isn't a standardized scale.
 The analog reading will vary depending on a number of variables having to do with soil type.
 
 Thus, to use this sensor, it's important to get two baseline readings at the outset of using this sensor.
 1 -- a reading of the soil you'll be sensing when it is completely dry.
 2 -- a reading of the soil you'll be sensing when it is saturated.

 This provides you with the low and high end of a moisture scale.
 
 */

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  
}
 
void loop() 
{
  float sensorValue;
  sensorValue = analogRead(A0);
  
  lcd.clear();
  lcd.print("Soil Moisture: ");
  lcd.setCursor(0,1);
  lcd.print(sensorValue);

  Serial.print("Soil Moisture: ");
  Serial.print(sensorValue);
  Serial.println();
  
  delay(3000);
}
