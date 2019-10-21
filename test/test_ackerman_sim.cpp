/**
 * @file test_ackerman_sim.cpp
 * @author Ashwin Varghese Kuruttukulam
 * @author Charan Karthikeyan
 * @brief Provides testing cases for the Ackerman SimulationClass.
 * @Copyright "Copyright 2019 <Ashwin Varghese Kuruttukulam>
 * @Copyright "Copyright 2019 <Charan Karthikeyan>
 */
#include <gtest/gtest.h>

#include "ackerman_sim.hpp"

/**
 * @brief Tests the function for the compute function of the \
 * ackerman simulation class.
 */
TEST(VaidateAckermanSim, TestCompute) {
  ackerman_sim ack_sim;
  double posX = 1, posY = 1, heading = 1;
  double *posXptr = &posX;
  double *posYptr = &posY;
  double *headingptr = &heading;
  double carLen = 1;

  double steering = 10, left = 1, right = 1;
  double *steeringptr = &steering;
  double *leftptr = &left;
  double *rightptr = &right;
  ack_sim.compute(steeringptr, leftptr, rightptr, posXptr, posYptr, headingptr,
                  carLen);
  EXPECT_NEAR(*headingptr, 1, 1);
}
