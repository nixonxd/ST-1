// Copyright 2025 UNN-CS
#include <cmath>
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value <= 1)
    return false;
  if (value == 2)
    return true;
  if (value % 2 == 0)
    return false;

  uint64_t limit = static_cast<uint64_t>(sqrt(value));
  for (uint64_t i = 3; i <= limit; i += 2) {
    if (value % i == 0)
      return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0)
    return 0;

  uint64_t count = 0;
  uint64_t number = 1;

  while (count < n) {
    ++number;
    if (checkPrime(number))
      ++count;
  }

  return number;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t res = value + 1;

  while (true) {
    if (checkPrime(res))
      return res;
    ++res;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;

  for (uint64_t j = 2; j < hbound; ++j) {
    if (checkPrime(j))
      sum += j;
  }

  return sum;
}
