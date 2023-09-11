#ifndef PID__h
#define PID__h

class PID
{


  public:

  
    PID(double*, double*, double*,        // * constructor.  links the PID to the Input, Output, and 
        double, double, double);          //   Setpoint.  Initial tuning parameters are also set here.
                                          


    bool Compute();                       // * performs the PID calculation.  it should be
                                          //   called every time loop() cycles.

    void SetOutputLimits(double, double); // * clamps the output to a specific range. 0-255 by default, but
										                      //   it's likely we want to change this depending on
										                      //   the application
										
										  
									
    
	double kp;                    //  *(P)roportional Tuning Parameter
    double ki;                    //   (I)ntegral Tuning Parameter
    double kd;                    //   (D)erivative Tuning Parameter

    double *myInput;              //  *Pointers to the Input, Output, and Setpoint variables
    double *myOutput;             //   This creates a hard link between the variables and the 
    double *mySetpoint;           //   PID, freeing the user from having to constantly tell us
                                  //   what these values are.  with pointers we'll just know.
			  
	unsigned long lastTime;
	double outputSum, lastInput;
	double outMin, outMax;
	
};
#endif