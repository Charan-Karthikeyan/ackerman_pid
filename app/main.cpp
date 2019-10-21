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

  // Heading and velocity to be achieved
  double headingSp = 2, velSp = 1;

  // Initializing simulation
  double nIterations = 40, temp;
  double simulationTime = 0.05;
  ackerman_sim simObj(simulationTime);

  // Initializing ackermann controller
  double heading = 1, baseLine = 1, carLen = 1, posX = 0, posY = 0;
  ackerman_controller ackermanObj(baseLine, carLen, kp, ki, kd, true,
                                  simulationTime);

  ackermanObj.setSetPoints(headingSp, velSp);
  std::cout << "The heading setpoint is : " << headingSp << std::endl
            << "Enter a value to continue...." << std::endl;
  std::cin >> temp;
  double lVel = velSp / 2, rVel = velSp / 2, steer = 0;

  // Running simulation
  for (int k = 1; k < nIterations; k++) {
    std::cout << "New Sim : \t " << k << std::endl;
    simObj.compute(steer, lVel, rVel, posX, posY, heading, carLen);
    std::cout << "Current Heading : " << heading << ", Current X Position : "
              << posX << ", Current Y Position : " << posY << std::endl;
    steer = ackermanObj.run(heading, rVel, lVel);
    std::cout << "Steering angle PID output : " << steer << std::endl
              << std::endl;
  }
  return 0;
}
