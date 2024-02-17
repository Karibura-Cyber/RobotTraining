#include <POP32.h>
 
void setup() {
  Serial.begin(9600);
  oled.begin();
}

void loop() {
  Serial.print(analogRead(A0));
  Serial.print("||");  
  Serial.print(analogRead(A1));
  Serial.print("||");  
  Serial.print(analogRead(A2));
  Serial.print("||");  
  Serial.print(analogRead(A3));
  Serial.print("||");  
  Serial.print(analogRead(A4));
  Serial.print("||");  
  Serial.print(analogRead(A5));
  Serial.print("||");  
  
  oled.text(0,0,"sensorFLL = %d",analogRead(A0));
  oled.text(1,0,"sensorFL  = %d",analogRead(A1));
  oled.text(2,0,"sensorFR  = %d",analogRead(A2));
  oled.text(3,0,"sensorFRR = %d",analogRead(A3));
  oled.text(4,0,"sensorBL  = %d",analogRead(A4));
  oled.text(5,0,"sensorBR  = %d",analogRead(A5));
  
  oled.show();
  oled.clear();
  
}
