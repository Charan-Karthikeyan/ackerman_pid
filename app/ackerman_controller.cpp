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

ackerman_controller::ackerman_controller(double baseline, double carLen) {
  ackerman_controller::baseline = baseline;
  ackerman_controller::carLen = carLen;
  ackerman_controller::lWheelVel = 0;
  ackerman_controller::rWheelVel = 0;
  ackerman_controller::radius = 0;
  ackerman_controller::velocitysp = 2;
  ackerman_controller::headingsp = 0;
  ackerman_controller::steerAng = 0;
}

void ackerman_controller::calcRadius(){
  ackerman_controller::radius = ackerman_controller::carLen*(tan(90-ackerman_controller::steerAng));

}

void ackerman_controller::calcWheelVel(){
  ackerman_controller::lWheelVel = ackerman_controller::velocitysp*(1-(ackerman_controller::baseline/2*ackerman_controller::radius));
  ackerman_controller::rWheelVel = ackerman_controller::velocitysp*(1+(ackerman_controller::baseline/2*ackerman_controller::radius));
}

double ackerman_controller::getHeadingPoints(){
  return ackerman_controller::headingsp;

}

double ackerman_controller::getVelocityPoints(){
  return ackerman_controller::velocitysp;

}

double ackerman_controller::compute(double headingFeedback , double &rWheelVel, double &lWheelVel){
  ackerman_controller::steerAng =pid::compute(headingFeedback);
  ackerman_controller::calcRadius();
  ackerman_controller::calcWheelVel();
  std::cout << "The Right wheel velocity is :\t" << &lWheelVel<< std::endl;
  std::cout << "The left wheel Velocity is :\t" << &rWheelVel << std::endl;
  return ackerman_controller::steerAng;
}

void ackerman_controller::setSetPoints(double headingsp,double velocitysp){
  ackerman_controller::headingsp = headingsp;
  ackerman_controller::velocitysp = velocitysp;

}
