#include <SoftwareSerial.h>

#define RF 10
#define RB 11
#define LF 6
#define LB 9
#define SPEEDL 200
#define SPEEDR 200

SoftwareSerial mySerial (7, 8);  //Rx, Tx

// 7 - Software Rx
// 8 - Software Tx

void setup() {
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  if (mySerial.available() > 0) {
    int s = mySerial.read();

    //    Serial.write(s);

    switch (s) {

      case ('F'):
        analogWrite(RF, SPEEDR);
        analogWrite(RB, 0);
        analogWrite(LF, SPEEDL);
        analogWrite(LB, 0);
        break;

      case ('B'):
        analogWrite(RF, 0);
        analogWrite(RB, SPEEDR);
        analogWrite(LF, 0);
        analogWrite(LB, SPEEDL);
        break;

      case ('L'):
        analogWrite(RF, SPEEDR);
        analogWrite(RB, 0);
        analogWrite(LF, 0);
        analogWrite(LB, SPEEDL);
        break;

      case ('R'):
        analogWrite(RF, 0);
        analogWrite(RB, SPEEDR);
        analogWrite(LF, SPEEDL);
        analogWrite(LB, 0);
        break;

      case ('G'):
        analogWrite(RF, SPEEDR);
        analogWrite(RB, 0);
        analogWrite(LF, 0);
        analogWrite(LB, 0);
        break;

      case ('I'):
        analogWrite(RF, 0);
        analogWrite(RB, 0);
        analogWrite(LF, SPEEDL);
        analogWrite(LB, 0);
        break;

      case ('H'):
        analogWrite(RF, 0);
        analogWrite(RB, 0);
        analogWrite(LF, 0);
        analogWrite(LB, SPEEDL);
        break;

      case ('J'):
        analogWrite(RF, 0);
        analogWrite(RB, SPEEDR);
        analogWrite(LF, 0);
        analogWrite(LB, 0);
        break;

      default:
        analogWrite(RF, 0);
        analogWrite(RB, 0);
        analogWrite(LF, 0);
        analogWrite(LB, 0);
        break;
    }
    //    delay(50);
  }
}
