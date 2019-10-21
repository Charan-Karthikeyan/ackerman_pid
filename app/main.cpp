/**
 * @file main.cpp
 * @author Ashwin Varghese Kuruttukulam
 * @author Charan Karthikeyan
 * @brief Main program that runs the pid, ackerman controller and the ackerman simulation classes.
 *
 * @Copyright "Copyright 2019 <Ashwin Varghese Kuruttukulam>
 * @Copyright "Copyright 2019 <Charan Karthikeyan>
 */
#include <iostream>
#include "ackerman_controller.hpp"
#include "ackerman_sim.hpp"
int main() {
  // PID tuning parameters
  double kp = -10, ki = 0, kd = 0;

  // Heading and velocity to be achieved. Heading should be -3.14 and +3.14
  double headingSp = 2, velSp = 1;

  // Initializing simulation
  double nIterations = 40, temp;
  double simulationTime = 0.05;
  ackerman_sim simObj(simulationTime);

  // Initializing ackermann controller
  double heading = 0, posX = 0, posY = 0;
  double *headingptr = &heading;
  double *posXptr = &posX;
  double *posYptr = &posY;
  double baseLine = 1, carLen = 1;
  ackerman_controller ackermanObj(baseLine, carLen, kp, ki, kd, true,
                                  simulationTime);

  ackermanObj.setSetPoints(headingSp, velSp);
  std::cout << "The heading setpoint is : " << headingSp << std::endl
            << "Enter a value and press enter...." << std::endl;
  std::cin >> temp;
  double lVel = velSp / 2, rVel = velSp / 2, steer = 0;
  double *lVelptr = &lVel;
  double *rVelptr = &rVel;
  double *steerptr = &steer;

  // Running simulation
  for (int k = 1; k < nIterations; k++) {
    std::cout << "Simulation Iteration No : \t " << k << std::endl;
    simObj.compute(steerptr, lVelptr, rVelptr, posXptr, posYptr, headingptr,
                   carLen);
    std::cout << "Current Heading : " << *headingptr
              << ", Current X Position : " << *posXptr
              << ", Current Y Position : " << *posYptr << std::endl;
    ackermanObj.run(steerptr, headingptr, rVelptr, lVelptr);
    std::cout << "Steering angle PID output : " << *steerptr << std::endl
              << std::endl;
  }
  return 0;
}
