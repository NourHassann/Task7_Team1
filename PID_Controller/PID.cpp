#include "Arduino.h"
#include <PID.h>

/*Constructor (...)*********************************************************
 *    The parameters specified here are those for for which we can't set up
 *    reliable defaults, so we need to have the user set them.
 ***************************************************************************/
PID::PID(double* Input, double* Output, double* Setpoint,
        double Kp, double Ki, double Kd)
{
    myOutput = Output;
    myInput = Input;
    mySetpoint = Setpoint;

    PID::SetOutputLimits(0, 255);				//default output limit corresponds to
												//the arduino pwm limits

    SampleTime = 100;							//default Controller Sample Time is 0.1 seconds


    lastTime = millis()-SampleTime;
}


// Compute() 
 
 
bool PID::Compute()
{
   unsigned long now = millis();
   unsigned long timeChange = (now - lastTime);
   if(timeChange>=SampleTime)
   {
      //Compute all the working error variables
      double input = *myInput;
      double error = *mySetpoint - input;
      double dInput = (input - lastInput);
      outputSum+= (ki * error);

      
      //Add Proportional on Error
	  double output;
      output = kp * error;
      
      //Compute Rest of PID Output
      output += outputSum - kd * dInput;

	  if(output > outMax){
         
         output = outMax;
      }
      else if(output < outMin){
       
       output = outMin;
      }
      
	  *myOutput = output;

      // Update Data
      lastInput = input;
      lastTime = now;
	  return true;
   }
}


/* SetOutputLimits(...)****************************************************
 *     This function will be used far more often than SetInputLimits.  while
 *  the input to the controller will generally be in the 0-1023 range (which is
 *  the default already,)  the output will be a little different.
 **************************************************************************/
void PID::SetOutputLimits(double Min, double Max)
{
   if(Min >= Max) return;
   outMin = Min;
   outMax = Max;

   
	if(*myOutput > outMax){ 
        
        *myOutput = outMax;
    }
	else if(*myOutput < outMin){
         
         *myOutput = outMin;
    }

	if(outputSum > outMax){
         
         outputSum= outMax;
    }
	else if(outputSum < outMin){
         
         outputSum= outMin;
    }
   
}

