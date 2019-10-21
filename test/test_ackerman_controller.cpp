/**
 * @file test_ackerman_controller.cpp
 * @author Ashwin Varghese Kuruttukulam
 * @author Charan Karthikeyan
 * @brief Provides testing cases for the Ackerman controller  Class.
 * @Copyright "Copyright 2019 <Ashwin Varghese Kuruttukulam>
 * @Copyright "Copyright 2019 <Charan Karthikeyan>
 */
#include <gtest/gtest.h>

#include "ackerman_controller.hpp"
/**
 * @brief Tests  one constructor the ackerman controller class
 */
TEST(ValidateAckermanController, TestConstructor) {
  ackerman_controller ack_cont(1, 1);
  EXPECT_EQ(ack_cont.getBaseLine(), 1);
  EXPECT_EQ(ack_cont.getCarLen(), 1);
}

/**
 * @brief Tests the second constructor of the ackerman controller class
 */
TEST(ValidateAckermanController, TestConstructor1) {
  ackerman_controller ack_cont(1, 1, 1, 0, 0, true, 0);
  EXPECT_EQ(ack_cont.getHeadingPoints(), 0);
  EXPECT_EQ(ack_cont.getVelocityPoints(), 2);
}

/**
 * @brief Tests the compute function in the ackerman controller class
 */
TEST(VaidateAckermanController, TestCompute) {
  double a = 1;
  double b = 2;
  ackerman_controller ack_cont(a, b);
  double lWheel = 1, rWheel = 1, heading = 10, steer = 0;
  double *lWheelptr = &lWheel;
  double *rWheelptr = &rWheel;
  double *headingptr = &heading;
  double *steerptr = &steer;
  ack_cont.setSetPoints(8, 2);
  ack_cont.setkp(1);
  ack_cont.run(steerptr, headingptr, rWheelptr, lWheelptr);
  EXPECT_EQ(*steerptr, 2);
  EXPECT_NEAR(*rWheelptr, 1.017, 0.05);
  EXPECT_NEAR(*lWheelptr, 0.982, 0.05);
}
/**
 * @brief Tests the setSetPoints in the ackerman controller class
 */
TEST(ValidateAckermanController, TestSetPoints) {
  ackerman_controller ack_cont(1, 1);
  ack_cont.setSetPoints(1, 2);
  EXPECT_EQ(ack_cont.getHeadingPoints(), 1);
  EXPECT_EQ(ack_cont.getVelocityPoints(), 2);
}

