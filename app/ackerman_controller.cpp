/**
 * @file ackerman_controller.cpp
 * @author Ashwin Varghese Kuruttukulam
 * @author Charan Karthikeyan
 * @brief Defines the function to calculate the Radius, wheel velocity
 * and update the current heading.
 * @Copyright "Copyright 2019 <Ashwin Varghese Kuruttukulam>
 * @Copyright "Copyright 2019 <Charan Karthikeyan>
 */

#include "ackerman_controller.hpp"
#include<iostream>

ackerman_controller::ackerman_controller(double baseline, double carLen) {
  ackerman_controller::pid(1, 0, 0, false);
  ackerman_controller::setdt(0.1);
  ackerman_controller::baseline = baseline;
  ackerman_controller::carLen = carLen;
  ackerman_controller::lWheelVel = 0;
  ackerman_controller::rWheelVel = 0;
  ackerman_controller::radius = 0;
  ackerman_controller::velocitysp = 2;
  ackerman_controller::headingsp = 0;
  ackerman_controller::steerAng = 0;
}

ackerman_controller::ackerman_controller(double baseline, double carLen,
                                         double kp, double ki, double kd,
                                         bool dtMode, double dt) {
  ackerman_controller::setkp(kp);
  ackerman_controller::setki(ki);
  ackerman_controller::setkd(kd);
  ackerman_controller::setdt(dt);
  ackerman_controller::setdtMode(dtMode);
  ackerman_controller::baseline = baseline;
  ackerman_controller::carLen = carLen;
  ackerman_controller::lWheelVel = 0;
  ackerman_controller::rWheelVel = 0;
  ackerman_controller::radius = 0;
  ackerman_controller::velocitysp = 2;
  ackerman_controller::headingsp = 0;
  ackerman_controller::steerAng = 0;
}

void ackerman_controller::calcRadius() {
  ackerman_controller::radius = ackerman_controller::carLen
      * (tan((3.14 / 2) - ackerman_controller::steerAng));

}

void ackerman_controller::calcWheelVel() {
  ackerman_controller::lWheelVel = ackerman_controller::velocitysp
      * (1 - (ackerman_controller::baseline / 2 * ackerman_controller::radius));
  ackerman_controller::rWheelVel = ackerman_controller::velocitysp
      * (1 + (ackerman_controller::baseline / 2 * ackerman_controller::radius));

}

double ackerman_controller::getHeadingPoints() {
  return ackerman_controller::headingsp;

}

double ackerman_controller::getVelocityPoints() {
  return ackerman_controller::velocitysp;

}

double ackerman_controller::run(double headingFeedback, double &rWheelVel,
                                double &lWheelVel) {
  ackerman_controller::steerAng = ackerman_controller::pid::compute(
      headingFeedback);
  ackerman_controller::calcRadius();
  ackerman_controller::calcWheelVel();
  std::cout<< "The velocity of the right wheel is " << rWheelVel << std::endl;
  std::cout << "The velocity of the left wheel is" << lWheelVel << std::endl;
  return ackerman_controller::steerAng;
}

void ackerman_controller::setSetPoints(double headingsp, double velocitysp) {
  ackerman_controller::headingsp = headingsp;
  ackerman_controller::setSp(headingsp);

  ackerman_controller::velocitysp = velocitysp;

}

double ackerman_controller::getBaseLine() {
  return ackerman_controller::baseline;
}

double ackerman_controller::getCarLen() {
  return ackerman_controller::carLen;
}

