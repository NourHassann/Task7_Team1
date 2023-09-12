# include "D:\My_GitHub\Task7_Team1\PID_class\src\problem.h"

#define Flow_Rate A0 
#define OUTPUT_PIN 3
#define Desired_FlowRate 90.00 //CFM 
double kp =2, ki =0.1, kd =0.01;
double setPoint = Desired_FlowRate*(100/255); // we assume flow meter is linear it's range from 0 to 100 CFM 

PID myPID(kp, ki, kd);
void setup()
{

  Serial.begin(9600);
  pinMode(Flow_Rate,INPUT);

  
}

void loop()
{
  myPID.setSetpoint(setPoint);
  myPID.calculateOutput(A0);
  error = myPID.getError();
  Serial.print("Error : \t");
  Serial.println(error);

  delay(10);
}
