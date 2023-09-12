#include "Arduino.h"
#include "problem.h"


PID::PID(double Kp, double Ki, double Kd)
{
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->integral_enabled = true;
  this->derivative_enabled = true;
}

void PID::setSetpoint(double setpoint)
{
    this->setpoint = setpoint;
}

double PID::calculateOutput(double* Input) 
{
    now = millis();
    dt = (now - lastTime);
    process_variable = *Input;
    this->error = setpoint - process_variable;
    this->integral += error * dt;
    this->derivative = (error - previous_error) / dt;
    this->output = Kp * error + Ki * integral + Kd * derivative;
    lastTime = now;
    previous_error = error;
    return output;
}

void PID::reset() 
{
    integral = 0;
    derivative = 0;
    previous_error = 0;
}

double PID::getError() 
{
    return error;
}

double PID::getIntegral() 
{
    return integral;
}

double PID::getDerivative() 
{
    return derivative;
}

double PID::getPreviousError() 
{
    return previous_error;
}

void PID::enableIntegral(bool enabled) 
{
    this->integral_enabled = enabled;
}

void PID::enableDerivative(bool enabled)
{
    this->derivative_enabled = enabled;
}
