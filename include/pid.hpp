/**
 * @file pid.hpp
 * @author Ashwin Varghese Kuruttukulam
 * @author Charan Karthikeyan
 * @brief Defines a PID Controller from the feedback/measured value
 * and the setpoint. The output of the PID is calculated as per the equation
 * output = Kp*Error + Ki*ErrorSum*dt + Kp*(Error-prevError)/dt
 *
 * @Copyright "Copyright 2019 <Ashwin Vargheese Kuruttukulam>
 * @Copyright "Copyright 2019 <Charan Karthikeyan>
 */
#pragma once

#include<iostream>
#include<string>
#include<chrono>

class pid {
 private:
  std::chrono::system_clock::time_point prevTime;
  double kp, ki, kd, prevError, errorSum, dtVal, setPoint;
  bool dtMode, firstRunFlag;
 public:
  /**
   * @brief Destructor for the PID Controller
   * @param None.
   * @return None.
   */
  ~pid();

  /**
   * @brief Constructor for the PID Controller, Initialize kp to 1, ki and kd to 0.
   * @param None.
   * @return None.
   */
  pid();

  /**
   * @brief Initialize the pid gain parameters to the parameter values
   * @param kp Proportional Gain of PID controller.
   * @param ki Integral Gain of PID controller.
   * @param kd Differential Gain of PID controller.
   * @return None.
   */
  pid(double kp, double ki, double kd);

  /**
   * @brief Initialize the pid gain parameters to the parameter values and set the dt mode type
   * dtMode = true means that the user will set the dt value and ensure that the
   * compute function is called at every dt seconds
   * @param kp Proportional Gain of PID controller.
   * @param ki Integral Gain of PID controller.
   * @param kd Differential Gain of PID controller.
   * @param dtMode Mode in which the pid controller works.
   * @return None.
   */

  pid(double kp, double ki, double kd, bool dtMode);

//  /**
//   * @brief Destructor for the PID Controller
//   * @param None.
//   * @return None.
//   */
//  ~pid();

  /**
   * @brief Function to compute the output of the PID controller as per the equation output = Kp*Error + Ki*ErrorSum*dt + Kp*(Error-prevError)/dt
   * If this function is being called for the first time after the initialization of the class, the prevTime variable
   * should be set to the current time. Also the derivative and integral term will not be used in the output equation
   * during the first call of this function, because prevTime and prevError is not available.
   * @param feedback Measured state value.
   * @return pidOut Output calculated by the PID controller with the equation.
   */

  double compute(double feedback);

  /**
   * @brief Function to set the value of bool to trigger automatic or manual setting of dt of the PID controller
   * @param set the boolean for control(dtMode).
   * @return None.
   */
  void setdtMode(bool dtMode);

  /**
   * @brief Function to set the value of the change in time value.
   * @param set the value of time change(dtVal).
   * return None.
   */
  void setdt(double dt);

  /**
   * @brief Function to set the value of setPoint for the target heading
   * @param setPoint Target Heading value.
   * @return None.
   */
  void setSp(double setPoint);

  /**
   * @brief Function to set the value of Proportional Gain of the PID controller
   * @param Proportional Gain(kp)
   * @return None.
   */
  void setkp(double);

  /**
   * @brief Function to set the value of Integral Gain  of the PID controller
   * @param Integral Gain (ki)
   * @return None.
   */
  void setki(double);

  /**
   * @brief Function to set the value for Differential Gain of the PID controller
   * @param Differential Gain (kd)
   * @return None.
   */
  void setkd(double);

  /**
   * @brief returns the value of boolean of the change in time mode for the controller
   * @param None.
   * @return The state of the boolean(dtMode)
   */
  bool getdtMode();

  /**
   * @brief returns the value of the change in time set.
   * @param None.
   * return The value of change in time(dtVal)
   */
  double getdt();

  /**
   * @brief returns the value of setPoint for the target heading
   * @param None.
   * @return The target heading(setPoint).
   */
  double getSp();

  /**
   * @brief Function to get the value of Proportional Gain of the PID controller
   * @param None
   * @return Proportional Gain(kp)
   */
  double getkp();

  /**
   * @brief returns the value of the Integral Gain of the PID controller
   * @param None.
   * @return Integral Gain(ki)
   */
  double getki();

  /**
   * @brief Function to return the value of the error sum and test purposes
   * @param None.
   * @return Error sum value(errorSum)
   */
  double getErrorSum();

  /**
   * @brief returns the value of the Differential Gain of the PID controller
   * @param None.
   * @return Differential Gain(kd)
   */
  double getkd();

  /**
   * @brief Function to return the value of previous error for testing purposes
   * @param None.
   * @return Previous error value(prevError).
   */
  double getPrevError();

  /**
   * @brief Function to reset the integral term to zero
   * @param None.
   * return None.
   */
  void reset();
};
