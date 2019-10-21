/**
 * @file ackerman_sim.hpp
 * @author Ashwin Varghese Kuruttukulam
 * @author Charan Karthikeyan
 * @brief Defines the function to simulate the ackerman steering
 * @Copyright "Copyright 2019 <Ashwin Varghese Kuruttukulam>
 * @Copyright "Copyright 2019 <Charan Karthikeyan>
 */

#pragma once

#include<iostream>

class ackerman_sim {
 private:
  double dt, posX, posY, updatedHeading;
 public:
  /**
   * @brief A Constructor for the simulator
   * @param None.
   * @return None.
   */
  ackerman_sim();

  /**
   * @brief A constructor for the ackerman simulation
   * @param Change in time(dt)
   * @return None.
   */
  ackerman_sim(double dt);

  /**
   * @brief Destructor for the ackerman simulation
   * @param None.
   * return None.
   */
  ~ackerman_sim();

  /**
   * @brief This function is called to update the vehicle heading as per the wheel velocities
   * and the steering angle
   * @param The steering angle computed for the car(steerAng)
   * @param The velocity of the right wheel(rWheelVel)
   * @return The x position, y position and new heading
   */
  void compute(double steerAng, double rWheelVel, double lWheelVel,
               double &posX, double &posY, double &updatedHeading,
               double carLen);

};
