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

pid::pid() {

}

pid::pid(double kp, double ki, double kd) {

}

pid::pid(double kp, double ki, double kd, bool dtMode) {

}

pid::~pid() {

}

double pid::compute(double feedback) {

}

void pid::setdtMode(bool dtMode) {

}

void pid::setdt(double dt) {

}

void pid::setSp(double setPoint) {

}

void pid::setkp(double kp) {

}

void pid::setki(double ki) {

}

void pid::setkd(double kd) {

}

bool pid::getdtMode() {

}

double pid::getdt() {

}

double pid::getSp() {

}

double pid::getkp() {

}

double pid::getki() {

}

double pid::getErrorSum(){

}

double pid::getkd() {

}

double pid::getPrevError(){

}

void pid::reset() {

}

