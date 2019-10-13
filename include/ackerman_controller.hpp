/**
 * @file ackermann_controller.hpp
 * @author Ashwin Varghese Kuruttukulam
 * @author Charan Karthikeyan
 * @brief Defines the ackerman controller that calculates the
 * ,Radius of the turn, velocity of each wheel and and the overall
 * velocity of the vehicle
 * @Copyright "Copyright 2019 <Ashwin Varghese Kuruttukulam>
 * @Copyright "Copyright 2019 <Charan Karthikeyan>
 */
#pragma once

#include <iostream>

class ackerman_controller{
 private:
  double baseline,carLen, radius, rWheelVel,lWheelVel, steerAng, velocitysp, headingsp;

  /**
   * @brief Function to calculate the Radius of the turn given an angle
   * Formula : radius = carLen * tan(steerAng)
   * @param None.
   * @return None.
   */
  void calcRadius();

  /**
   * brief Function to calculate the wheel velocity of each wheel
   * and the velocity of the overall system
   * Formula : lWheelVel = velocitysp * (1-(baseline/2*radius))
   * Formula : rWheelVel = velocitysp * (1+(baseline/2*radius))
   * @param None.
   * @return None.
   */
  void calcWheelVel();

 public:

  /**
   * @brief Function to get the value of the heading setpoints
   * @param None.
   * @return Points of the heading.
   */
  double getHeadingPoints();

  /**
   * @brief Function to get the values of velocity setpoints
   * @param None.
   * @return Points for the Velocity points.
   */
  double getVelocityPoints();

  /**
   * @brief Function to compute the steering angle, wheel velocity of the right and left wheels
   * @param The feedback about the heading from the PID controller.
   * @return The values of steering angle, the velocity of the right and left wheels.
   */
  double compute(double headingFeedback, double &rWheelVel, double &lWheelVel);

  /**
   * TODO : check the brief
   * @brief Function to update the target points.
   * @param heading set point of the target point(headingsp)
   * @param velocity of the set point(velocitysp)
   * @return None.
   */
  void setSetPoints(double headingsp, double velocitysp);
};

