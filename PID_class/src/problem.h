#ifndef PROBLEM_H
#define PROBLEM_H

class PID
{
    public:

    /*************************Basic Methods****************************/
        PID(double, double, double);

        void setSetpoint(double);

        double calculateOutput(int);

        void SetOutputLimits(double, double);

        void reset();
    /***************************May be Needed*************************/    
        double getError();

        double getIntegral();

        double getDerivative();

        double getPreviousError();

        void enableIntegral(bool);

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