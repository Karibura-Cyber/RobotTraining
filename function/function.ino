#include <POP32.h>
#define sensorFLL  448 //เซ็นเซอร์หน้าซ้ายA0
#define sensorFL   966 //เซ็นเซอร์ตรงกลางA1
#define sensorFR   723 //เซ็นเซอร์ตรงกลางA2
#define sensorFRR  740 //เซ็นเซอร์หน้าขวาA3

void setup() {
  waitSW_OK();
  beep();

}

void loop() {
  FC();
  ao();
}


void FC()  {
  if (analogRead(A0) > sensorFLL  && analogRead(A3) > sensorFRR) {
      motor(12, 80);   
      motor(34, 78);
  }
  if  (analogRead(A0) < sensorFLL  && analogRead(A3) < sensorFRR) {
      motor(12, 0);   
      motor(34, 0);
  }
  ao();
}
