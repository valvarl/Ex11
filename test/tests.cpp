// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include <string>
#include "train.h"

TEST(TrainTest, test1) {
Train train(1000);
EXPECT_EQ(1000, train.calculate());
}

TEST(TrainTest, test2) {
Train train(100000);
EXPECT_EQ(100000, train.calculate());
}

TEST(TrainTest, test3) {
Train train(10000000);
EXPECT_EQ(10000000, train.calculate());
}

