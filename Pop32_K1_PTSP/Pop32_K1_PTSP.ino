#include <POP32.h>
#define sensorFLL  448 //เซ็นเซอร์หน้าซ้ายA0
#define sensorFL   966 //เซ็นเซอร์ตรงกลางA1
#define sensorFR   723 //เซ็นเซอร์ตรงกลางA2
#define sensorFRR  740 //เซ็นเซอร์หน้าขวาA3
#define sensorBL   1370 //เซ็นเซอร์หลังซ้ายA4
#define sensorBR   986 //เซ็นเซอร์หลังขวาA5


///////////////////////////////////////////////////////////////////////////
#define MaxSpeedL  80  //ล้อซ้ายความเร็วเดินหน้าเช็คเร็ว
#define MaxSpeedR  78   //ล้อขวาความเร็วเดินหน้าเช็คเร็ว
#define LowSpeedL  20  //ล้อซ้ายความเร็วเดินหน้าเช็คช้า
#define LowSpeedR  20  //ล้อขวาความเร็วเดินหน้าเช็คช้า

///////////////////////////////////////////////////////////////////////////
#define B_MaxSpeedL  30  //ล้อซ้ายความเร็วถอยหลังเช็ค
#define B_MaxSpeedR  30  //ล้อขวาความเร็วถอยหลังเช็ค

///////////////////////////////////////////////////////////////////////////
#define Speed_stage  60   //สปีดการกลับเข้าเส้น ค่าต้องมากกว่า set_to_stage
#define set_to_stage  20 //สปีดการกลับเข้าเส้น 8่ายิ่งน้อยยิ่งกลับตัวแรง

//////////////////////////////////////////////////////////////////////////
#define turn1  190        //หน่วงเวลาในการเลี้ยวซ้าย  ****ใส่เป็นเวลา****** //L
#define turn2  180        //หน่วงเวลาในการเลี้ยวขวา  ****ใส่เป็นเวลา****** //R
#define turn3  220 
#define turnB  370        //หน่วงเวลาในการกลับหลังหัน  ****ใส่เป็นเวลา****** //R
#define Delay  60        //หน่วงเวลาเถอยหลัง ก่อนเลี้ยว ***ใส่เป็นเวลา****

///////////////////////////////////////////////////////////////////////////
long CH[9] = {0, 200, 470, 750, 950, 1100, 1200, 1400};//จับเส้น ใช่กับ FC
//จับเส้นระยะการเคลื่อนทีแต่ละช่อง {0,1ช่อง,2ช่อง,3ช่อง,4ช่อง,5ช่อง,6ช่อง,7ช่อง} //หาค่าก่อนใช้งาน

///////////////////////////////////////////////////////////////////////////
long CH1[9] = {0, 235, 470, 695, 950, 1100, 1200, 1400}; //ไม่จับเส็น ใช่กับ T และ FT
//ไม่จับเส็นระยะการเคลื่อนทีแต่ละช่อง {0,1ช่อง,2ช่อง,3ช่อง,4ช่อง,5ช่อง,6ช่อง,7ช่อง} //หาค่าก่อนใช้งาน

///////////////////////////////////////////////////////////////////////////
long CH2[9] = {0, 150, 430, 580, 800, 1100, 1200, 1400}; //จับเส็น ใช่กับ FS
//จับเส็นระยะการเคลื่อนทีแต่ละช่อง {0,1ช่อง,2ช่อง,3ช่อง,4ช่อง,5ช่อง,6ช่อง,7ช่อง} //หาค่าก่อนใช้งาน

///////////////////////////////////////////////////////////////////////////

//FC(ช่อง);วิ่งเช็คดำเช็คข้าง เช่น อยากเดิน 3 ช่องให้ใส่ 3 ได้เลย ไม่นับแผ่นตัวเอง
//FT(ช่อง); วิ่งหน่วงเวลาเช็คข้าง เช่น อยากเดิน 3 ช่องให้ใส่ 3 ได้เลย ไม่นับแผ่นตัวเอง
//T(ช่อง);วิ่งหน่วงเวลา เช่น อยากเดิน 3 ช่องให้ใส่ 3 ได้เลย ไม่นับแผ่นตัวเอง
//BC1();ถอยหลังจากเส้นสีดำ
//BC2();ถอยหลังจากพื้นสีเขียว
//L1();หันขวา
//R1();หันขวา
//RT();กลับหลังหัน
//FS(ช่อง);วิ่งเช็คเขียวเช็คข้าง เช่น อยากเดิน 2 ช่องให้ใส่ 2 ได้เลย ไม่นับแผ่นตัวเอง
//SD1();ทั้งลูกถอยหลัง
//SD2();ทั้งลูกถอยหลังใช้กับ BC2
//TT(40,40,1500); วิ่งข้ามตะเกียบ (ความเร็วล้อซ้าย,ความเร็วล้อขวา,เวลา)

void setup() {
  servo(1, 92);
 // servo(1, 25);
}
///////////////////////////////////////////////////////////////////////////
void loop() {
  waitSW_OK();
  beep();
  FC(3);
  R1();
  FC(3);
  R1();
  FC(1);
  R1();
  FC(2);
  ao(); 
  bk(20); delay(200);
  L1();
  ao();   
  FC(2);
  SD1(); //จบ1
  L1B();
  ao(); delay(1000);
  FC(7);
  ao();
  R1();
  ao();
  FC(1);
  R1();
  ao();  
  FC(4);
  SD1();
  ao(); //จบ2
  RT();
  ao();
  FC(3);
  L1();
  ao(); 
  FC(4);
  L1();
  ao();
  FC(2);
  ao();  //จุดพอยท์ 1
  RT();
  ao();
  FC(2); 
  R1();
  ao(); 
  FT(2);
  ao(); delay(1000);
  L1();
  ao(); 
  FC(3);
  ao(); 
  L1();
  ao();  
  FC(1);
  L1();
  FC(1);
  SD1();
  ao();  //จบ3
  RT();
  ao();
  FC(1);
  R1();
  FC(3);
  SD1();
  ao(); //จบ4
  
/*FT(4);
  ao(); delay(1000);
  R1();
  ao(); delay(1000);
  FC(1);
  R1();
  FC(1);
  SD1();
  ao(); */
}


///////////////////////////////////////////////////////////////////////////
void FC (int TIME) { // เดินหน้าเจอเส้น
  long cur = millis();
  while (millis() - cur <= CH[TIME]) {
    if (analogRead(A0) > sensorFLL  && analogRead(A3) > sensorFRR) {
      motor(12, MaxSpeedL);   //ล้อซ้ายความเร็วเดินหน้าเช็คเร็ว
      motor(34, MaxSpeedR);   //ล้อขวาความเร็วเดินหน้าเช็คเร็ว
    }
    else if (analogRead(A0) > sensorFLL && analogRead(A3) < sensorFRR) {
      motor(12, set_to_stage);
      motor(34, Speed_stage);
    }
    else if (analogRead(A0) < sensorFLL && analogRead(A3) > sensorFRR) {
      motor(12, Speed_stage);
      motor(34, set_to_stage);
    }
  }
  AO();
  delay(10);
  while (analogRead(A1) > sensorFL  || analogRead(A2) > sensorFR) { 
    if (analogRead(A0) > sensorFLL  && analogRead(A3) > sensorFRR) {
      motor(12, LowSpeedL );  //ล้อซ้ายความเร็วเดินหน้าเช็คช้า
      motor(34, LowSpeedR );  //ล้อขวาความเร็วเดินหน้าเช็คช้า
    }
    else if (analogRead(A0) > sensorFLL && analogRead(A3) < sensorFRR ) {
      motor(12, set_to_stage );
      motor(34, Speed_stage );
    }
    else if (analogRead(A0) < sensorFLL && analogRead(A3) > sensorFRR ) {
      motor(12, Speed_stage );
      motor(34, set_to_stage );
    }
  }
  AO();
  set1();
  AO();
  delay(Delay);
  motor(12, -50);
  motor(34, -50);
  delay(Delay);
  AO();
}
void set1() {
  /////// ปรับแก้ตัวค้านหน้า
  while (analogRead(A0)  > sensorFLL) {
    motor(12, 40);
    motor(34, -45);
  }
  AO();

  while (analogRead(A3) > sensorFRR) {
    motor(12, -45);
    motor(34, 40);
  }
  AO();
}

///////////////////////////////////////////////////////////////////////////
void FT (int TIME) {
  long cur = millis();
  while (millis() - cur <= CH1[TIME]) {
    if (analogRead(A0) > sensorFLL  && analogRead(A3) > sensorFRR) {
      motor(12, 70);   //ล้อซ้ายความเร็วเดินหน้าเช็คเร็ว
      motor(34, 60);   //ล้อขวาความเร็วเดินหน้าเช็คเร็ว
    }
    else if (analogRead(A0) > sensorFLL && analogRead(A3) < sensorFRR) {
      motor(12, set_to_stage);
      motor(34, Speed_stage);
    }
    else if (analogRead(A0) < sensorFLL && analogRead(A3) > sensorFRR) {
      motor(12, Speed_stage);
      motor(34, set_to_stage);
    }
  }
  AO();
  delay(Delay);
  AO();
}

///////////////////////////////////////////////////////////////////////////
void T (int TIME) {
  long cur = millis();
  while (millis() - cur <= CH1[TIME]) {
    motor(12, MaxSpeedL);   //ล้อซ้ายความเร็วเดินหน้าเช็คเร็ว
    motor(34, MaxSpeedR);   //ล้อขวาความเร็วเดินหน้าเช็คเร็ว
  }
  AO();
}

///////////////////////////////////////////////////////////////////////////
void BC1() {
  while (analogRead(A4) > sensorBL  || analogRead(A5) > sensorBR) {
    motor(12, -B_MaxSpeedL); 
    motor(34, -B_MaxSpeedR); 
  }
  //ปรับตัวด้านหนัง
  if (analogRead(A4) < sensorBL) {
    motor(12, 0);
    motor(34, 0);
  }
  if (analogRead(A5) < sensorBR) {
    motor(12, 0);
    motor(34, 0);
  }
  AO();
  delay(100);
  AO();
  motor(12, 50);
  motor(34, 50);
  delay(Delay);
  AO();
}


///////////////////////////////////////////////////////////////////////////
void BC2() {
  while (analogRead(A4) > sensorBL  || analogRead(A5) > sensorBR) {
    motor(12, -B_MaxSpeedL);
    motor(34, -B_MaxSpeedR);
  }
  AO();
  delay(100);
  AO();
  motor(12, 50);
  motor(34, 50);
  delay(Delay + 85);
  AO();
}

///////////////////////////////////////////////////////////////////////////
void L1B() {
  motor(12, -100);
  motor(34, 100);
  delay(turn3);
  AO();
  delay(Delay);
  AO();
}

void L1() {
  motor(12, -100);
  motor(34, 100);
  delay(turn1);
  AO();
  delay(Delay);
  AO();
}
void R1() {
  motor(12, 100);
  motor(34, -100);
  delay(turn2);
  AO();
  delay(Delay);
  AO();
}
void RT() {
  motor(12, 100);
  motor(34, -100);
  delay(turnB);
  AO();
  delay(Delay + 50);
  AO();
}


///////////////////////////////////////////////////////////////////////////
void SD2() {
  AO();
  servo(1, 92); //เข้า
  delay(100);
  servo(1, 25), ///ออก
        delay(500);
  servo(1, 92); //เข้า
  motor(12, -60); //ถอยหลังจากทิ้ง
  motor(34, -60); //ถอยหลังจากทิ้ง
  delay(120);//เวลา
  AO();
}
void SD1() {
  AO();
  servo(1, 92); //เข้า
  delay(100);
  servo(1, 25), ///ออก
        delay(500);
  servo(1, 92); //เข้า
  motor(12, -80); //ถอยหลังจากทิ้ง
  motor(34, -80); //ถอยหลังจากทิ้ง
  delay(140);//เวลา
  AO();
}
void FS (int TIME) { // เดินหน้าเจอเส้น
  long cur = millis();
  while (millis() - cur <= CH2[TIME]) {
    if (analogRead(A0) > sensorFLL  && analogRead(A3) > sensorFRR) {
      motor(12, MaxSpeedL);   //ล้อซ้ายความเร็วเดินหน้าเช็คเร็ว
      motor(34, MaxSpeedR);   //ล้อขวาความเร็วเดินหน้าเช็คเร็ว
    }
    else if (analogRead(A0) > sensorFLL && analogRead(A3) < sensorFRR) {
      motor(12, set_to_stage);
      motor(34, Speed_stage);
    }
    else if (analogRead(A0) < sensorFLL && analogRead(A3) > sensorFRR) {
      motor(12, Speed_stage);
      motor(34, set_to_stage);
    }
  }
  AO();
  delay(10);
  while (analogRead(A1) > sensorFL  || analogRead(A8) > sensorFR) {
    if (analogRead(A0) > sensorFLL  && analogRead(A3) > sensorFRR) {
      motor(12, LowSpeedL );  //ล้อซ้ายความเร็วเดินหน้าเช็คช้า
      motor(34, LowSpeedR );  //ล้อขวาความเร็วเดินหน้าเช็คช้า
    }
    else if (analogRead(A0) > sensorFLL && analogRead(A3) < sensorFRR ) {
      motor(12, set_to_stage );
      motor(34, Speed_stage );
    }
    else if (analogRead(A0) < sensorFLL && analogRead(A3) > sensorFRR ) {
      motor(12, Speed_stage );
      motor(34, set_to_stage );
    }
  }
  AO();
  set1();
  AO();
}

///////////////////////////////////////////////////////////////////////////
void TT (int SpeedL, int SpeedR, int TIME) {
  long cur = millis();
  while (millis() - cur <= TIME) {
    motor(12, SpeedL);   //ล้อซ้ายความเร็วเดินหน้าเช็คเร็ว
    motor(34, SpeedR);   //ล้อขวาความเร็วเดินหน้าเช็คเร็ว
  }
  AO();
}
