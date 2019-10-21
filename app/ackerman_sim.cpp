/**
 * @file ackerman_sim.cpp
 * @author Ashwin Varghese Kuruttukulam
 * @author Charan Karthikeyan
 * @brief Declarations of the function to simulate the ackerman steering
 * @Copyright "Copyright 2019 <Ashwin Varghese Kuruttukulam>
 * @Copyright "Copyright 2019 <Charan Karthikeyan>
 */

#include"ackerman_sim.hpp"


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

void ackerman_sim::compute(double steerAng, double rWheelVel, double lWheelVel,
                           double &posX, double &posY, double &heading,
                           double carLen) {
  double vehVel = (rWheelVel + lWheelVel) / 2*carLen;  //vehicle center velocity
  if (steerAng > (3.14 / 4))
    steerAng = 3.14 / 4;
  else if (steerAng < (-3.14 / 4))
    steerAng = -3.14 / 4;

  if (steerAng != 0) {
    double turnRad = vehVel * tan((3.14 / 2) - steerAng);  //calculating turning radius
    double angVel = vehVel / turnRad;  // calculating angular velocity
    heading = heading + angVel * dt;  //updating heading
  }
  posX += -vehVel * dt * sin(heading);
  posY += vehVel * dt * cos(heading);
}

