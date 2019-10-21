#include <gtest/gtest.h>

#include "ackerman_sim.hpp"

TEST(VaidateAckermanSim,TestCompute) {
  ackerman_sim ack_sim;
  double posX, posY, heading = 1;
  //TODO calculate the value of and add to the EQ from the cpp file.
  ack_sim.compute(10, 1, 1, posX, posY, heading, 1);
  EXPECT_NEAR(heading, 1, 1);

}
