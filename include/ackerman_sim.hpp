/**
 * @file ackerman_sim.hpp
 * @author Ashwin Varghese Kuruttukulam
 * @author Charan Karthikeyan
 * @brief Defines the function to simulate the ackerman steering
 * @Copyright "Copyright 2019 <Ashwin Varghese Kuruttukulam>
 * @Copyright "Copyright 2019 <Charan Karthikeyan>
 */

#ifndef INCLUDE_ACKERMAN_SIM_HPP_
#define INCLUDE_ACKERMAN_SIM_HPP_

#include <math.h>
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
  explicit ackerman_sim(double dt);

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
   * @param The velocity of the left wheel(lWheelVel)
   * @param The positionf the vehicle in the x axis(posx)
   * @param The positionf the vehicle in the y axis(posy)
   * @param The length of the car or vehiclr(carLen)
   * @param The updated heading of the vehicle(updatedHeading)
   * @return The x position, y position and new heading
   */
  void compute(double *steerAng, double *rWheelVel, double *lWheelVel,
               double *posX, double *posY, double *updatedHeading,
               double carLen);
};

#endif  // INCLUDE_ACKERMAN_SIM_HPP_ //
