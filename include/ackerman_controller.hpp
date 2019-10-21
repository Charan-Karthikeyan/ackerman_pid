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
#ifndef INCLUDE_ACKERMAN_CONTROLLER_HPP_
#define INCLUDE_ACKERMAN_CONTROLLER_HPP_

#include <iostream>
#include <cmath>
#include"pid.hpp"

class ackerman_controller : public pid {
 private:
  double baseline, carLen, radius, rWheelVel, lWheelVel, steerAng, velocitysp,
      headingsp;

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
   * @brief Initialize the car parameters
   * @param distance between left and right wheels(baseline)
   * @param distance between front and back wheels(carLength)
   * @return
   */
  ackerman_controller(double baseline, double carLength);

  /**
   * @brief Second Constructor to initialize all the parameters
   * @param The distance between the two wheels of a car(baseline)
   * @param The distance between the front and back of the vehicle(carLen)
   * @param The integral gain(ki)
   * @param The Propotional gain(kp)
   * @param The differential gain(kd)
   * @param The mode of operation for the pid(dtMode) true for automatic and false for manual.
   * @param The change in time (dt)
   * @return None.
   */

  ackerman_controller(double baseline, double carLen, double kp, double ki,
                      double kd, bool dtMode, double dt);

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
   * @param The feedback about the heading from the PID controller(headingFeedback).
   * @param The velocity of the right and left wheels(rWheelVel, lWheelVel)(only for testing we use these values)
   * @return The values of steering angle, the velocity of the right and left wheels.
   */
  void run(double *steerAng, double *headingFeedback, double *rWheelVel,
           double *lWheelVel);

  /**
   * @brief Function to update the target points.
   * @param heading set point of the target point(headingsp)
   * @param velocity of the set point(velocitysp)
   * @return None.
   */
  void setSetPoints(double headingsp, double velocitysp);

  /**
   * @brief Function to get the value of baseline (for testing purpose only)
   * @param None
   * @return The value baseline
   */
  double getBaseLine();

  /**
   * @brief Function to return the value of car length (For testing purpose only)
   * @param None.
   * @return The value of the length of the car
   */
  double getCarLen();
};
#endif  // INCLUDE_ACKERMAN_CONTROLLER_HPP_//
