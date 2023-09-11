#define Flow_Rate A0 
#define OUTPUT_PIN 3

double dt, last_time;  
double integral, previous, output = 0;
double kp, ki, kd;
double Desired_FlowRate = 90.00;
double FlowRate = 0;

void setup()
{
  kp = 2 ; 
  ki = 0.1;
  kd = 0.01;
  last_time = 0;
  Serial.begin(9600);
  pinMode(Flow_Rate,INPUT);
  analogWrite(OUTPUT_PIN, 0);
  delay(10);
}

void loop()
{
  double now = millis();
  dt = (now - last_time)/1000.00;
  last_time = now;

  double actual = analogRead(Flow_Rate); //Read the feedback from the flow meter
  FlowRate = actual*60 / 1023 ; // Calculate the flow rate in CFM 
  double error = Desired_FlowRate - FlowRate; // Calculate the error signal 
  output = pid(error); // Apply PID algorthim

  analogWrite(OUTPUT_PIN, output); 

  // Desired_FlowRate VS FlowRate
  Serial.print(Desired_FlowRate);
  Serial.print(",");
  Serial.println(FlowRate);

  // Error
  Serial.println(error);

  delay(10);
}
// PID Calculation Function
double pid(double error)
{
  // P Controller
  double proportional = error;
  // I Controller
  integral += error * dt;
  // D Controller
  double derivative = (error - previous) / dt;
  // Update Data
  previous = error;
  // PID Equation
  double output = (kp * proportional) + (ki * integral) + (kd * derivative);
  return output;
}
