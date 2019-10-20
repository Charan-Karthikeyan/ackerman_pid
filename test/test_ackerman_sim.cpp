#include <gtest/gtest.h>

#include "ackerman_sim.hpp"

TEST(VaidateAckermanController,TestCompute) {
  ackerman_sim ack_sim;
  double posX, posY, heading;
  //TODO calculate the value of and add to the EQ from the cpp file.
  ack_sim.compute(1, 10, 1, 1, posX, posY, heading, 1);
  EXPECT_NEAR(heading, 1, 1);

}
