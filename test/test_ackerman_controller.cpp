#include <gtest/gtest.h>

#include "ackerman_controller.hpp"

TEST(VaidateAckermanController,TestCompute){
  ackerman_controller ack_cont;
  //TODO calculate the value of and add to the EQ from the cpp file.
  EXPECT_EQ(ack_cont.compute(10),);

}

TEST(ValidateAckermanController,TestchangeSetPoints){
  //TODO add the final value after computing
  ackerman_controller ack_cont;
  EXPECT_EQ(ack_cont.changeSetPoints(),);
}


