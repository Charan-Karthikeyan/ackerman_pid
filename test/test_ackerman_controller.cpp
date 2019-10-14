#include <gtest/gtest.h>

#include "ackerman_controller.hpp"

TEST(VaidateAckermanController,TestCompute) {
  ackerman_controller ack_cont;
  //TODO calculate the value of and add to the EQ from the cpp file.

  EXPECT_EQ(ack_cont.compute(10),);

}

TEST(ValidateAckermanController,TestSetPoints) {
  //TODO add the final value after computing
  ackerman_controller ack_cont;
  ack_cont.setSetPoints(1, 2);
  double heading, vel;

  EXPECT_EQ(ack_cont.getHeadingPoints(), 1);
  EXPECT_EQ(ack_cont.getVelocityPoints(), 1);
}

