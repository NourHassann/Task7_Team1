#include <PID_v1.h>

#define Flow_Rate A0 
#define OUTPUT_PIN 3

double kp, ki, kd;
double Desired_FlowRate = 90.00;
double FlowRate = 0;
double current_FlowRate;

void setup()
{
  kp = 2 ; 
  ki = 0.1;
  kd = 0.01;

  Serial.begin(9600);
  pinMode(Flow_Rate,INPUT);
  analogWrite(OUTPUT_PIN, 0);

  PID myPID(FlowRate, current_Rate, Desired_FlowRate, kp, ki, kd, DIRECT);
  myPID.SetMode(AUTOMATIC);
  delay(10);
}

void loop()
{

  double actual = analogRead(Flow_Rate); //Read the feedback from the flow meter
  FlowRate = actual*60 / 1023 ; // Calculate the flow rate in CFM 
  double error = Desired_FlowRate - FlowRate; // Calculate the error signal 

  myPID.Compute();

  analogWrite(OUTPUT_PIN, current_FlowRate); 

  // Desired_FlowRate VS FlowRate
  Serial.print(Desired_FlowRate);
  Serial.print(",");
  Serial.println(FlowRate);

  // Error
  Serial.println(error);

  delay(10);
}
