int led1=2;
int led2=3;
int led3=4;
int led4=5;
int led5=6;
int time = 300;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  for(int ledOn = led1; ledOn<led5; ledOn++){
    digitalWrite(ledOn, HIGH);
    delay(time);
  }
  for(int ledOff=led1; ledOff<led5; ledOff++){
    digitalWrite(ledOff, LOW);
    delay(time);
  }
}
