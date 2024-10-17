#define RF 9
#define RB 10
#define LF 3
#define LB 6
#define SPEED_R 180
#define SPEED_R 180
#define SPEED 180
void setup() {
pinMode(RF, OUTPUT);
pinMode(RB, OUTPUT);
pinMode(LF, OUTPUT);
pinMode(LB, OUTPUT);
}

void loop() {
analogWrite(RF, 0);
analogWrite(RB, 0);
analogWrite(LF, 0);
analogWrite(LB, 0);
}
