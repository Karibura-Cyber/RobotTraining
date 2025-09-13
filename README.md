13-14 SEP 2025
COMPLETED CODE

```cpp
#include <ipst.h>

int l,r;
int threshold_l = (420 + 50) / 2;             //THRESHOLD FOR LEFT SENSOR
int threshold_r = (420 + 50) / 2;             //THRESHOLD FOR RIGHT SENSOR

void setup() {
  OK();
}

void loop() {
  l = analog(0);
  r = analog(1);

  if (l < threshold_l){
    sl(50);
    // tl(50);
    // motor(1, 10); motor(2, 50);
  }
  else if(r < threshold_r) {
    sr(50);
    // tr(50);
    // motor(1, 50); motor(2, 10);
  }
  else{
    fd(50);
  }


  // glcdClear();
  // glcd(0, 0, "L: %d", l);
  // glcd(1,0, "R: %d", r);
  // delay(100);


}
```
