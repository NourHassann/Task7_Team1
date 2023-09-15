# include <problem.h>
/*****************************************************Macros Start*****************************************************************/
#define Flow_Rate A0  // feedback signal
#define OUTPUT_PIN 3  // PWM arduino pin to control the motor speed 
#define Desired_FlowRate 90.00 //CFM 
/******************************************************Macros End******************************************************************/
/*********************************************Global Deceleration Start************************************************************/
double kp =2, ki =0.1, kd =0.01; 
double Input =0, Output = 0, error=0; 
double setPoint = Desired_FlowRate*(255/100); // we assume flow meter is linear it's range from 0 to 100 CFM 
/**********************************************Global Deceleration End*************************************************************/
PID myPID(kp, ki, kd);
void setup()
{

  Serial.begin(9600);
  pinMode(Flow_Rate,INPUT);
  pinMode(OUTPUT_PIN,OUTPUT);
  
}

void loop()
{
  //Read Feedback signal.
  Input = map(analogRead(Flow_Rate),0,1023,0,255); 
  // set the target value.
  myPID.setSetpoint(setPoint);
  //calculate PID.
  Output = myPID.calculateOutput(&Input); 
  analogWrite(OUTPUT_PIN, Output); 
  // Get Error and print it.
  error = myPID.getError();
  Serial.print("Error : \t");
  Serial.println(error);
  delay(10);
}
