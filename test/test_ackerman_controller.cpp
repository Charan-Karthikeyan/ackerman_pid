#include <gtest/gtest.h>

#include "ackerman_controller.hpp"

TEST(VaidateAckermanController,TestCompute) {
  double a = 1;
  double b = 2;
  ackerman_controller ack_cont(a, b);
  double lWheel = 1;
  double rWheel = 1;
  ack_cont.setSetPoints(8, 2);
  ack_cont.setkp(1);
  EXPECT_EQ(ack_cont.run(10, rWheel, lWheel), 2);
  EXPECT_NEAR(rWheel, 1.017, 0.2);
  EXPECT_NEAR(lWheel, 0.982, 0.2);

}

TEST(ValidateAckermanController,TestSetPoints) {
  ackerman_controller ack_cont(1, 1);
  ack_cont.setSetPoints(1, 2);
  EXPECT_EQ(ack_cont.getHeadingPoints(), 1);
  EXPECT_EQ(ack_cont.getVelocityPoints(), 2);
}

