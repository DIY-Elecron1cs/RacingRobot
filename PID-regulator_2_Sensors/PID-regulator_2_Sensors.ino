#define Data_Left A3
#define Data_Right A4
#define Left_Motor_Forward 11
#define Left_Motor_Backwards 6
#define Right_Motor_Forward 5
#define Right_Motor_Backwards 3
#define Base_Speed 255 // Variable 1

float K_p = 2.3, K_i = 0.07 , K_d = 0.278; 
float dt = 0.002; // Variable 5
float Error, Integral_Error, Diff_Error, Previous_Error = 0;
float Control_PID;

uint16_t Left_Sensor, Right_Sensor;
uint16_t Set_Point_Left, Set_Point_Right;

int Sensors_Set_Difference, Sensors_Difference;

void Calculate_PID(void);
void Motor_Control(void);
void Clear_Integral(void);

void setup() {
  pinMode(Data_Left, INPUT);
  pinMode(Data_Right, INPUT);
  pinMode(Left_Motor_Forward, OUTPUT);
  pinMode(Left_Motor_Backwards, OUTPUT);
  pinMode(Right_Motor_Forward, OUTPUT);
  pinMode(Left_Motor_Forward, OUTPUT);
  delay(2500);
  Set_Point_Left = analogRead(Data_Left);
  Set_Point_Right = analogRead(Data_Right);
  Sensors_Set_Difference = Set_Point_Right - Set_Point_Left;
}

void loop() {
  Left_Sensor = analogRead(Data_Left);
  Right_Sensor = analogRead(Data_Right);
  Sensors_Difference = Right_Sensor - Left_Sensor;
  Calculate_PID();
  delay(dt*1000);
  Motor_Control();
}

void Calculate_PID() {
  Error = Sensors_Set_Difference - Sensors_Difference;
  Integral_Error += Error * dt;
  Diff_Error = (Error - Previous_Error) / dt;
  Previous_Error = Error;
  Control_PID = K_p * Error + K_i * Integral_Error + K_d * Diff_Error;
}


void Clear_Integral() {
}

void Motor_Control() {
  analogWrite(Left_Motor_Forward, Base_Speed - constrain(Control_PID, -Base_Speed, Base_Speed));
  analogWrite(Right_Motor_Forward, Base_Speed + constrain(Control_PID, -Base_Speed, Base_Speed));
  digitalWrite(Left_Motor_Backwards, LOW);
  digitalWrite(Right_Motor_Backwards, LOW);
}
