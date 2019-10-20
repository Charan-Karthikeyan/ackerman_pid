/**
 * @file ackerman_sim.cpp
 * @author Ashwin Varghese Kuruttukulam
 * @author Charan Karthikeyan
 * @brief Declarations of the function to simulate the ackerman steering
 * @Copyright "Copyright 2019 <Ashwin Varghese Kuruttukulam>
 * @Copyright "Copyright 2019 <Charan Karthikeyan>
 */

#include"ackerman_sim.hpp"
#include <math.h>

ackerman_sim::ackerman_sim() {
  ackerman_sim::dt = 0.01;  // default value for dt
  ackerman_sim::posX = 0;
  ackerman_sim::posY = 0;
  ackerman_sim::updatedHeading = 0;
}

ackerman_sim::~ackerman_sim() {

}

ackerman_sim::ackerman_sim(double dt) {
  ackerman_sim::dt = dt;
  ackerman_sim::posX = 0;
  ackerman_sim::posY = 0;
  ackerman_sim::updatedHeading = 0;
}

void ackerman_sim::compute(double currentHeading, double steerAng,
                           double rWheelVel, double lWheelVel, double &posX,
                           double &posY, double &updatedHeading,
                           double carLen) {
  double vehVel = (rWheelVel + lWheelVel) / 2;  //vehicle center velocity
  double turnRad = vehVel * tan(steerAng);  //calculating turning radius
  double angVel = vehVel / turnRad;  // calculating angular velocity

  posX += -vehVel * dt * sin(currentHeading);
  posY += vehVel * dt * cos(currentHeading);
  updatedHeading = currentHeading + angVel * dt;  //updating heading
}

