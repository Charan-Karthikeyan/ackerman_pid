/**
 * @file test_pid.cpp
 * @author Ashwin Varghese Kuruttukulam
 * @author Charan Karthikeyan
 * @brief Provides testing cases for the PID Class.
 * @Copyright "Copyright 2019 <Ashwin Varghese Kuruttukulam>
 * @Copyright "Copyright 2019 <Charan Karthikeyan>
 */
#include <gtest/gtest.h>

#include "pid.hpp"
/**
 * @brief Tests the constructor for the PID class
 */

TEST(ValidatePIDClass, TestpidConstructor) {
  pid mypid(1, 0, 0, false);
  mypid.setdt(0.5);
  EXPECT_EQ(mypid.getdt(), 0.5);
  EXPECT_EQ(mypid.getkp(), 1);
  EXPECT_EQ(mypid.getki(), 0);
  EXPECT_EQ(mypid.getkd(), 0);
  EXPECT_EQ(mypid.getdtMode(), false);
}
/**
 * @brief Tests the second constructor of the PID class
 */

TEST(ValidatePIDClass, TestpidConstructor2) {
  pid mypid(1, 10, 2000);
  EXPECT_EQ(mypid.getkp(), 1);
  EXPECT_EQ(mypid.getki(), 10);
  EXPECT_EQ(mypid.getkd(), 2000);
}
/**
 * @brief Test the compute function in the PID class
 */

TEST(ValidatePIDClass, Testcompute) {
  pid mypid(1, 0, 0);
  mypid.setSp(12);
  EXPECT_EQ(mypid.getSp(), 12);
  EXPECT_EQ(mypid.compute(10), -2);
}
/**
 * @brief Tests the reset function in the PID class
 */
TEST(ValidatePIDClass, Testreset) {
  pid mypid(1, 0, 0);
  double temp = mypid.compute(10);
  EXPECT_NE(temp, 0);
  mypid.reset();
  EXPECT_EQ(mypid.getPrevError(), 0);
  EXPECT_EQ(mypid.getErrorSum(), 0);
}

