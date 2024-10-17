#define RF 6
#define RB 9
#define LF 10
#define LB 11

#define SPEED 255
void setup() {
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
}

void loop() {
  analogWrite(RF, SPEED);
  analogWrite(RB, 0);
  analogWrite(LF, 0);
  analogWrite(LB, 0);
  delay(800);


  analogWrite(RF, 0);
  analogWrite(RB, 0);
  analogWrite(LF, 0);
  analogWrite(LB, 0);
  delay(150);
  
  analogWrite(RF, 0);
  analogWrite(RB, SPEED);
  analogWrite(LF, 0);
  analogWrite(LB, 0);
  delay(800);


  analogWrite(RF, 0);
  analogWrite(RB, 0);
  analogWrite(LF, 0);
  analogWrite(LB, 0);
  delay(150);
  
  analogWrite(RF, 0);
  analogWrite(RB, 0);
  analogWrite(LF, SPEED);
  analogWrite(LB, 0);
  delay(800);


  analogWrite(RF, 0);
  analogWrite(RB, 0);
  analogWrite(LF, 0);
  analogWrite(LB, 0);
  delay(150);
  
  analogWrite(RF, 0);
  analogWrite(RB, 0);
  analogWrite(LF, 0);
  analogWrite(LB, SPEED);
  delay(800);

  analogWrite(RF, 0);
  analogWrite(RB, 0);
  analogWrite(LF, 0);
  analogWrite(LB, 0);
  delay(150);
}
