#ifndef PROBLEM_H
#define PROBLEM_H

/**
 * @class PID
 * @brief handles the tuning for PID controller
*/
class PID
{
    public:

    /*************************Basic Methods****************************/
        /**
        * PID - initializes the tuning constants
        * @param Kp: Proportional tuning constant
        * @param Ki: Integral tuning constant
        * @param Kd: Differential tuning constant
        */
        PID(double, double, double);

        /**
        * setSetpoint - sets the setpoint
        * @param setpoint: the setpoint to be set
        */
        void setSetpoint(double);

        /**
        * calculateOutput - calculates the output based on the input signal,
        * mapping the input analog signal and get the output from the
        * tuning coefficients.
        * @param Feedbak_pin: the pin to read the input signal from.
        */
        double calculateOutput(double*);

        void SetOutputLimits(double, double);

        /**
        * reset - resets the state to the initial conditions
        */
        void reset();
    /***************************May be Needed*************************/    
    
        /**
        * getError - returns the value of the proportional error
        * @return proportional error
        */
        double getError();

        /**
        * getIntegral - returns the value of the integral error
        * @return integral error
        */
        double getIntegral();

        /**
        * getDerivative - returns the value of the differential error
        * @return differential error
        */
        double getDerivative();

        /**
        * getPreviousError - returns the previous error value
        * @return previous error
        */
        double getPreviousError();

        /**
        * enableIntegral - enables the integral constant
        * @param: boolean for the integral coeffiecient set.
        */
        void enableIntegral(bool);

        /**
        * enableDerivative - enables the differential constant
        * @param: boolean for the differential coefficient set.
        */
        void enableDerivative(bool);


    private:
        double Kp;
        double Ki;
        double Kd;
        double setpoint;
        double process_variable;
        double error;
        double integral;
        double derivative;
        double previous_error;
        double dt = 0;
        double lastTime = 0;
        double now = 0;
        bool integral_enabled;
        bool derivative_enabled;     
};

#endif
