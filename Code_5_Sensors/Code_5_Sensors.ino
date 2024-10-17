// 00100 - центр линии
// 10000 - право линии
// 00001 - лево линии

float Kp = 0.5, Ki = 0.5, Kd = 0.5;
float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;
int sensor [5] = {0, 0, 0, 0, 0};
int inital_motor_speed = 100;

#define pwm1 9
#define pwm2 3
#define MotLeftP1 9
#define MotLeftP2 6
#define MotRightP1 10
#define MotRightP2 11

void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);

void setup() {
  pinMode(pwm1, OUTPUT);       //PWM Pin 1
  pinMode(pwm2, OUTPUT);       //PWM Pin 2
  pinMode(MotLeftP1, OUTPUT);  //Left Motor Pin 1
  pinMode(MotLeftP2, OUTPUT);  //Left Motor Pin 2
  pinMode(MotRightP1, OUTPUT); //Right Motor Pin 1
  pinMode(MotRightP2, OUTPUT); //Right Motor Pin 2
  Serial.begin(9600);
}
/*
  Значения массива         Значение ошибки:
  датчиков:
  00001                    4
  00011                    3
  00010                    2
  00110                    1
  00100                    0
  01100                    -1
  01000                    -2
  11000                    -3
  10000                    -4
  00000                    5 или -5
*/
void read_sensor_values() {
  sensor [0] = digitalRead (A0);
  sensor [1] = digitalRead (A1);
  sensor [2] = digitalRead (A2);
  sensor [3] = digitalRead (A3);
  sensor [4] = digitalRead (A4);

  if ((sensor [0] == 0) && (sensor [1] == 0) && (sensor [2] == 0) && (sensor [3] == 0)  && (sensor [4] == 1)) {
    error = 4;
  }
  else {
    if ((sensor [0] == 0) && (sensor [1] == 0) && (sensor [2] == 0) && (sensor [3] == 0)  && (sensor [4] == 1)) {
      error = 3;
    }
    else {
      if ((sensor [0] == 0) && (sensor [1] == 0) && (sensor [2] == 0) && (sensor [3] == 1)  && (sensor [4] == 0)) {
        error = 2;
      }
      else {
        if ((sensor [0] == 0) && (sensor [1] == 0) && (sensor [2] == 1) && (sensor [3] == 1)  && (sensor [4] == 0)) {
          error = 1;
        }
        else {
          if ((sensor [0] == 0) && (sensor [1] == 0) && (sensor [2] == 1) && (sensor [3] == 0)  && (sensor [4] == 0)) {
            error = 0;
          }
          else {
            if ((sensor [0] == 0) && (sensor [1] == 1) && (sensor [2] == 1) && (sensor [3] == 0)  && (sensor [4] == 0)) {
              error = -1;
            }
            else {
              if ((sensor [0] == 0) && (sensor [1] == 0) && (sensor [2] == 0) && (sensor [3] == 0)  && (sensor [4] == 1)) {
                error = -2;
              }
              else {
                if ((sensor [0] == 1) && (sensor [1] == 1) && (sensor [2] == 0) && (sensor [3] == 0)  && (sensor [4] == 1)) {
                  error = -3;
                }
                else {
                  if ((sensor [1] == 0) && (sensor [1] == 0) && (sensor [2] == 0) && (sensor [3] == 0)  && (sensor [4] == 1)) {
                    error = -4;
                  }
                  else {
                    if ((sensor [1] == 0) && (sensor [1] == 0) && (sensor [2] == 0) && (sensor [3] == 0)  && (sensor [4] == 0)) {
                      if (error == -4) {
                        error = 5;
                      }
                      else {
                        error = 5;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

void calculate_pid() {
  P = error;
  I = I + previous_I;
  D = error - previous_error;
  PID_value = (Kp * P) + (Ki * I) + (Kd * D);
  previous_I = I;
  previous_error = error;
}

void motor_control() {
  int left_motor_speed = inital_motor_speed - PID_value;
  int right_motor_speed = inital_motor_speed + PID_value;

  constrain(left_motor_speed, 0, 150);
  constrain(right_motor_speed, 0, 200);
  analogWrite(pwm1, inital_motor_speed - PID_value);   //Left Motor Speed
  analogWrite(pwm2, inital_motor_speed + PID_value);   //Right Motor Speed

  digitalWrite(MotLeftP1, HIGH);
  digitalWrite(MotLeftP2, LOW);
  digitalWrite(MotRightP1, LOW);
  digitalWrite(MotRightP2, HIGH);
}

void loop(){
  read_sensor_values();
  calculate_pid();
  motor_control();
}
