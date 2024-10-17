#include <Servo.h>
Servo servo1;
int DELAY = 200;
int GRAD;
void setup(){
  servo1.attach(11);
  Serial.begin(9600);
}
void loop(){
  if (Serial.available() > 0){
    GRAD = Serial.parseInt();
    Serial.println(GRAD);
    servo1.write(GRAD);
    delay(DELAY);
  }
}
