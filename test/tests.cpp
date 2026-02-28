// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

TEST(checkPrimeTest, SmallNumbers) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
  EXPECT_TRUE(checkPrime(2));
  EXPECT_TRUE(checkPrime(3));
  EXPECT_FALSE(checkPrime(4));
  EXPECT_TRUE(checkPrime(5));
  EXPECT_FALSE(checkPrime(6));
  EXPECT_TRUE(checkPrime(7));
  EXPECT_FALSE(checkPrime(8));
  EXPECT_FALSE(checkPrime(9));
  EXPECT_FALSE(checkPrime(10));
}

TEST(checkPrimeTest, PrimeNumbers) {
  EXPECT_TRUE(checkPrime(13));
  EXPECT_TRUE(checkPrime(17));
  EXPECT_TRUE(checkPrime(19));
  EXPECT_TRUE(checkPrime(23));
  EXPECT_TRUE(checkPrime(29));
  EXPECT_TRUE(checkPrime(31));
  EXPECT_TRUE(checkPrime(37));
  EXPECT_TRUE(checkPrime(41));
  EXPECT_TRUE(checkPrime(43));
  EXPECT_TRUE(checkPrime(47));
}

TEST(checkPrimeTest, EvenNumbers) {
  EXPECT_FALSE(checkPrime(1000));
  EXPECT_FALSE(checkPrime(10000));
  EXPECT_FALSE(checkPrime(1000000));
}

TEST(checkPrimeTest, LargePrime) {
  EXPECT_TRUE(checkPrime(104729));
  EXPECT_TRUE(checkPrime(1299709));
}

TEST(nPrimeTest, FirstPrimes) {
  EXPECT_EQ(nPrime(1), 2);
  EXPECT_EQ(nPrime(2), 3);
  EXPECT_EQ(nPrime(3), 5);
  EXPECT_EQ(nPrime(4), 7);
  EXPECT_EQ(nPrime(5), 11);
  EXPECT_EQ(nPrime(6), 13);
  EXPECT_EQ(nPrime(7), 17);
  EXPECT_EQ(nPrime(8), 19);
  EXPECT_EQ(nPrime(9), 23);
  EXPECT_EQ(nPrime(10), 29);
}

TEST(nPrimeTest, NthPrimeValues) {
  EXPECT_EQ(nPrime(20), 71);
  EXPECT_EQ(nPrime(30), 113);
  EXPECT_EQ(nPrime(40), 173);
  EXPECT_EQ(nPrime(50), 229);
}

TEST(nPrimeTest, ZeroInput) { EXPECT_EQ(nPrime(0), 0); }

TEST(nPrimeTest, LargeN) {
  EXPECT_EQ(nPrime(100), 541);
  EXPECT_EQ(nPrime(200), 1223);
  EXPECT_EQ(nPrime(500), 3571);
}

TEST(nextPrimeTest, BasicNextPrimes) {
  EXPECT_EQ(nextPrime(2), 3);
  EXPECT_EQ(nextPrime(3), 5);
  EXPECT_EQ(nextPrime(5), 7);
  EXPECT_EQ(nextPrime(7), 11);
  EXPECT_EQ(nextPrime(11), 13);
}

TEST(nextPrimeTest, AfterCompositeNumbers) {
  EXPECT_EQ(nextPrime(4), 5);
  EXPECT_EQ(nextPrime(6), 7);
  EXPECT_EQ(nextPrime(8), 11);
  EXPECT_EQ(nextPrime(9), 11);
  EXPECT_EQ(nextPrime(10), 11);
  EXPECT_EQ(nextPrime(12), 13);
}

TEST(nextPrimeTest, AfterZeroAndOne) {
  EXPECT_EQ(nextPrime(0), 2);
  EXPECT_EQ(nextPrime(1), 2);
}

TEST(nextPrimeTest, LargeNumbers) {
  EXPECT_EQ(nextPrime(100), 101);
  EXPECT_EQ(nextPrime(200), 211);
  EXPECT_EQ(nextPrime(500), 503);
  EXPECT_EQ(nextPrime(1000), 1009);
}

TEST(sumPrimeTest, SmallSums) {
  EXPECT_EQ(sumPrime(10), 17);
  EXPECT_EQ(sumPrime(20), 77);
  EXPECT_EQ(sumPrime(30), 129);
}

TEST(sumPrimeTest, SumWithBounds) {
  EXPECT_EQ(sumPrime(2), 0);
  EXPECT_EQ(sumPrime(3), 2);
  EXPECT_EQ(sumPrime(5), 5);
  EXPECT_EQ(sumPrime(7), 10);
}

TEST(sumPrimeTest, KnownSums) {
  EXPECT_EQ(sumPrime(100), 1060);
  EXPECT_EQ(sumPrime(200), 4227);
  EXPECT_EQ(sumPrime(500), 21536);
}

TEST(sumPrimeTest, LargeSum) {
  uint64_t res = sumPrime(2000000);
  uint64_t expected = 142913828922;
  EXPECT_EQ(expected, res);
}
