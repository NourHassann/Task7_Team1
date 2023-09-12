/*
 *  Name : Group 1
 *  Date : 10-Sep-2023
 *  Breif: control DC motor using Cytron and using Exponential smoothing filter to soft start. 
 */
/************************************************Macros Start************************************************************/
#define Limit_sw 7 //Limit switch at top of robot tank to indicate if the tank is full or not.
#define Motor_Dir 8
#define Motor_Speed 9
/*************************************************Macros End*************************************************************/

/********************************************Global Deceleration Start***************************************************/
int Y_fil[2]={0,0};  //the final output signal.
int out_signal; //PWM value which is the input for the filter.
/*********************************************Global Deceleration End****************************************************/

/********************************************Function Deceleration Start*************************************************/
void Soft_start (int output,bool Dir );
/********************************************Function Deceleration End***************************************************/
void setup() {
  // initial serial communication
  Serial.begin(9600);
  pinMode(Limit_sw, INPUT_PULLUP);
  pinMode(Motor_Speed, OUTPUT);
  pinMode(Motor_Dir, OUTPUT);
}

void loop() {
   //call the function to start the movement. ------- it will works until the tank is full"limit_sw ==HIGH" .
  while(digitalRead(Limit_sw)== LOW)
  {
  Soft_start(255, LOW);   
  }

}
/*********************************************Function Definition Start**************************************************/

//function control the motor direction and speed, output is the PWM value and Dir is logic state to control the direction.
void Soft_start (int output, bool Dir){

    Y_fil[1] = 0.9 * Y_fil[0]+ 0.1 * output;
    digitalWrite(Motor_Dir, Dir); //LOW -> clockwise ------ HIGH -> counter clockwise.
    analogWrite(Motor_Speed, Y_fil[1]);
    Y_fil[0] = Y_fil[1];
    Serial.println(Y_fil[1]);
    delay(50);

}
/**********************************************Function Definition End***************************************************/