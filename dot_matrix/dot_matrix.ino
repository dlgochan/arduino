#include <LedControl.h>
#define DIN 12
#define CLK 11 
#define CS 10

LedControl DM(DIN, CLK, CS, 1);

// 점멸
void setup() {
  Serial.begin(9600);
  Serial.println();
  DM.shutdown(0, false);
  DM.setIntensity(0, 1);
  DM.clearDisplay(0);
}

void loop() {
  int row, column;

  for(row=0; row<8; row++){
    if(row % 2 == 0){ // row가 짝수
       for(column=0; column<8; column+=2){
        DM.setLed(0, row, column, true);
        delay(100);
       }
    }
    else{
       for(column=1; column<8; column+=2){
        DM.setLed(0, row, column, true);
        delay(100);
       }
    }
  }
  

  for(row=0; row<8; row++){
    if(row % 2 == 0){ // row가 짝수
       for(column=0; column<8; column+=2){
        DM.setLed(0, row, column, false);
        delay(100);
       }
    }
    else{
       for(column=1; column<8; column+=2){
        DM.setLed(0, row, column, false);
        delay(100);
       }
    }
  }
  
}

///////////////////////////////////////////////////
//
//byte heart[] = {
//  0b01101100,
//  0b10010010,
//  0b10000010,
//  0b01000100,
//  0b00010000
//};
//
//void setup() {
//  DM.shutdown(0, false);
//  DM.setIntensity(0, 1);
//  DM.clearDisplay(0);
//}
//
//void loop() {
//  int size=sizeof(heart)/sizeof(byte);
//  for(int i=0; i<size; i++){
//    DM.setRow(0, i, heart[i]);
//    delay(100);
//  }
//  DM.clearDisplay(0);
//  delay(100);
//}
