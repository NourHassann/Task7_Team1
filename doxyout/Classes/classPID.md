---
title: PID
summary: handles the tuning for PID controller 

---

# PID



handles the tuning for [PID]() controller 


`#include <problem.h>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[PID](Classes/classPID.md#function-pid)**(double Kp, double Ki, double Kd) |
| void | **[setSetpoint](Classes/classPID.md#function-setsetpoint)**(double setpoint) |
| double | **[calculateOutput](Classes/classPID.md#function-calculateoutput)**(int Feedback_pin) |
| void | **[SetOutputLimits](Classes/classPID.md#function-setoutputlimits)**(double , double ) |
| void | **[reset](Classes/classPID.md#function-reset)**() |
| double | **[getError](Classes/classPID.md#function-geterror)**() |
| double | **[getIntegral](Classes/classPID.md#function-getintegral)**() |
| double | **[getDerivative](Classes/classPID.md#function-getderivative)**() |
| double | **[getPreviousError](Classes/classPID.md#function-getpreviouserror)**() |
| void | **[enableIntegral](Classes/classPID.md#function-enableintegral)**(bool enabled) |
| void | **[enableDerivative](Classes/classPID.md#function-enablederivative)**(bool enabled) |

## Public Functions Documentation

### function PID

```cpp
PID(
    double Kp,
    double Ki,
    double Kd
)
```


**Parameters**: 

  * **Kp** Proportional tuning constant 
  * **Ki** Integral tuning constant 
  * **Kd** Differential tuning constant 


[PID](Classes/classPID.md) - initializes the tuning constants 


### function setSetpoint

```cpp
void setSetpoint(
    double setpoint
)
```


**Parameters**: 

  * **setpoint** the setpoint to be set 


setSetpoint - sets the setpoint 


### function calculateOutput

```cpp
double calculateOutput(
    int Feedback_pin
)
```


**Parameters**: 

  * **Feedbak_pin** the pin to read the input signal from. 


calculateOutput - calculates the output based on the input signal, mapping the input analog signal and get the output from the tuning coefficients. 


### function SetOutputLimits

```cpp
void SetOutputLimits(
    double ,
    double 
)
```


### function reset

```cpp
void reset()
```


reset - resets the state to the initial conditions 


### function getError

```cpp
double getError()
```


**Return**: proportional error 

getError - returns the value of the proportional error 


### function getIntegral

```cpp
double getIntegral()
```


**Return**: integral error 

getIntegral - returns the value of the integral error 


### function getDerivative

```cpp
double getDerivative()
```


**Return**: differential error 

getDerivative - returns the value of the differential error 


### function getPreviousError

```cpp
double getPreviousError()
```


**Return**: previous error 

getPreviousError - returns the previous error value 


### function enableIntegral

```cpp
void enableIntegral(
    bool enabled
)
```


**Parameters**: 

  * **** boolean for the integral coeffiecient set. 


enableIntegral - enables the integral constant 


### function enableDerivative

```cpp
void enableDerivative(
    bool enabled
)
```


**Parameters**: 

  * **** boolean for the differential coefficient set. 


enableDerivative - enables the differential constant 


-------------------------------

Updated on 2023-09-12 at 23:19:57 +0200