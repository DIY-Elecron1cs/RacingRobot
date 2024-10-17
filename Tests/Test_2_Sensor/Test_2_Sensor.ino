int LineSensorL;
int LineSensorR;
void setup(){  
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
}
void loop(){
LineSensorL = analogRead (A0);
LineSensorR = analogRead (A1);
Serial.print(LineSensorL);
Serial.print('\t');
Serial.println(LineSensorR);
delay(300);
}
