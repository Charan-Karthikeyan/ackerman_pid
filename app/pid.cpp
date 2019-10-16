/**
 * @file pid.cpp
 * @author Ashwin Varghese Kuruttukulam
 * @author Charan Karthikeyan
 * @brief Defines a PID Controller from the feedback/measured value
 * and the setpoint. The output of the PID is calculated as per the equation
 * output = Kp*Error + Ki*ErrorSum*dt + Kp*(Error-prevError)/dt
 * @Copyright "Copyright 2019 <Ashwin Varghese Kuruttukulam>
 * @Copyright "Copyright 2019 <Charan Karthikeyan>
 */

#include "pid.hpp"
#include <chrono>

pid::pid() {
  pid::kp = 1;
  pid::ki = 0;
  pid::kd = 0;
  pid::prevError = 0;
  pid::errorSum = 0;
  pid::prevTime = std::chrono::system_clock::now();
  pid::dtMode = false;
  pid::dtVal = 0.1;
  pid::setPoint = 0;
  pid::firstRunFlag = true;
}

pid::pid(double kp, double ki, double kd) {
  pid::kp = kp;
  pid::ki = ki;
  pid::kd = kd;
  pid::prevError = 0;
  pid::errorSum = 0;
  pid::prevTime = std::chrono::system_clock::now();
  pid::dtMode = false;
  pid::dtVal = 0.1;
  pid::setPoint = 0;
  pid::firstRunFlag = true;

}

pid::pid(double kp, double ki, double kd, bool dtMode) {
  pid::kp = kp;
  pid::ki = ki;
  pid::kd = kd;
  pid::prevError = 0;
  pid::errorSum = 0;
  pid::prevTime = std::chrono::system_clock::now();
  pid::dtMode = dtMode;
  pid::dtVal = 0.1;
  pid::setPoint = 0;
  pid::firstRunFlag = true;

}

pid::~pid() {

}

double pid::compute(double feedback) {
  double currError, output, dError;
  currError = feedback - pid::setPoint;  // Calculating error
  pid::errorSum += currError;  // Updating sum of error
  dError = currError - pid::prevError;

  if (pid::firstRunFlag == false) {

    //updating dtVal
    if (pid::dtMode == false) {
      std::chrono::system_clock::time_point currTime =
          std::chrono::system_clock::now();
      std::chrono::duration<double> elapsed_seconds;
      elapsed_seconds = currTime - pid::prevTime;
      pid::dtVal = elapsed_seconds.count();  //updating dt
    }

    output = pid::kp * currError + pid::ki * pid::errorSum * pid::dtVal
        + pid::kd * dError / pid::dtVal;  // Calculating the pid output

  } else {
    output = pid::kp * currError;
    firstRunFlag = false;
  }
  pid::prevError = currError;
  pid::prevTime = std::chrono::system_clock::now();
  return output;
}

void pid::setdtMode(bool dtMode) {
  pid::dtMode = dtMode;
}

void pid::setdt(double dt) {
  pid::dtVal = dt;
}

void pid::setSp(double setPoint) {
  pid::setPoint = setPoint;

}

void pid::setkp(double kp) {
  pid::kp = kp;
}

void pid::setki(double ki) {
  pid::ki = ki;

}

void pid::setkd(double kd) {
  pid::kd = kd;

}

bool pid::getdtMode() {
  return pid::dtMode;
}

double pid::getdt() {
  return pid::dtVal;
}

double pid::getSp() {
  return pid::setPoint;
}

double pid::getkp() {
  return pid::kp;
}

double pid::getki() {
  return pid::ki;
}
double pid::getkd() {
  return pid::kd;
}

double pid::getErrorSum() {
  return pid::errorSum;
}

double pid::getPrevError() {
  return pid::prevError;
}

void pid::reset() {
  pid::errorSum = 0;
  pid::prevError = 0;
  pid::firstRunFlag = 0;
}

