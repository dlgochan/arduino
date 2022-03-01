#include <Keypad.h>

char secretCode[5] = "1234";
int position = 0;
int wrong = 0;

const byte Rows=4;
const byte Cols=4;
byte rowPins[Rows] = {9,8,7,6};
byte colPins[Cols] = {5,4,3,2};
char keys[Rows][Cols] ={
  {'D','C','B','A'},
  {'#','9','6','3'},
  {'0','8','5','2'},
  {'*','7','4','1'},
}; 
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, Rows, Cols);

int ledB = 12;
int ledG = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("start");
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  setLocked(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = customKeypad.getKey();
  Serial.println("loop start");
  if (key){
    Serial.println(key);
  }
  if((key >= '0' && key <= '9') || (key >= 'A' && key <= 'D') || (key == '*' || key == '#')){
    if(key == '*' || key == '#'){
      position = 0;
      wrong = 0;
      setLocked(true);
    }
    else if(key == secretCode[position]){
      position++;
      wrong = 0;
    }
    else if(key != secretCode[position]){
      position = 0;
      setLocked(true);
      wrong++;
    }
    if(position == 4){
      setLocked(false);
    }
    if(wrong == 4){
      blink();
      wrong = 0;  
    }
  }
  delay(100);
}

void setLocked(int locked){
  if(locked){
    digitalWrite(ledG, HIGH);
    digitalWrite(ledB, LOW);  
  }
  else{
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, HIGH);
  }
}

void blink(){
  for(int i=0; i<8; i++){
    digitalWrite(ledG, LOW);
    delay(100);
    digitalWrite(ledG, HIGH);
    delay(100);  
  }
}



















