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
  double posX, posY, heading = 1;
  ack_sim.compute(10, 1, 1, posX, posY, heading, 1);
  EXPECT_NEAR(heading, 1, 1);
}
