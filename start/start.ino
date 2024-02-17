#include <POP32.h>

void setup() {
  waitSW_OK();
  beep();
  servo (1,92);
}

void loop() {
   motor(12, 50);   
   motor(34, 50);
   delay(500);
   ao();
   sr(50);
   delay(500);
   ao();
}
