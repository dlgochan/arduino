
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int ledR = 3;
int ledG = 2;
int sound = 9;
int water = A0;


// 시리얼 모니터에 수위 센서 값 출력
//
//void setup() {
//  // put your setup code here, to run once:
//   Serial.begin(9600);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  int waterValue = analogRead(water);
//  delay(100);
//
//  Serial.print("water value: ");
//  Serial.println(waterValue);
//  delay(100);
//}


// 액체의 양 체크하기

void setup(){
  Serial.begin(9600);
  Serial.println("start");
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
}

void loop(){
  int waterValue = analogRead(water);
  delay(100);

  Serial.print("water value: ");
  Serial.println(waterValue);
  delay(100);

  if(waterValue<550){
    digitalWrite(ledR, HIGH);
    digitalWrite(ledG, LOW);
    for(int i=0; i<5; i++){
      analogWrite(sound, 200);
      delay(1000);
      analogWrite(sound, 0);
      delay(1000);  
    }  
  }
  else{
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH);
    analogWrite(sound, 0);  
  }
}

// 액정디스플레이를 추가하여 액체의 양 체

//void setup(){
////  Serial.begin(9600);
////  Serial.println("start");
//  pinMode(ledR, OUTPUT);
//  pinMode(ledG, OUTPUT);
//  lcd.init();
//  lcd.backlight();
//  lcd.clear();
//}
//
//void loop(){
//  int waterValue = analogRead(water);
//  delay(100);
//  lcd.setCursor(0,0);
//  lcd.print("water value: ");
//  lcd.setCursor(0,1);
//  lcd.print(waterValue);
//  delay(100);
//  lcd.clear();
//  
//  if(waterValue<550){
//    digitalWrite(ledR, HIGH);
//    digitalWrite(ledG, LOW);
//    for(int i=0; i<5; i++){
//      analogWrite(sound, 200);
//      delay(1000);
//      analogWrite(sound, 0);
//      delay(1000);  
//    }  
//  }
//  else{
//    digitalWrite(ledR, LOW);
//    digitalWrite(ledG, HIGH);
//    analogWrite(sound, 0);  
//  }
//}
