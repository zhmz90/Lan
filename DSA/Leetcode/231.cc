/* Copyright 2017 Lanting Guo */
/** 231. Power of Two

Given an integer, write a function to determine if it is a power of two.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using string = std::string;

class Solution {
 public:
    bool isPowerOfTwo(int n) {
      if (n <  1) return false;
      if (n == 1) return true;
      if (n == 2) return true;
      if (n % 2 != 0) return false;
      return isPowerOfTwo(n/2);
    }
};


int main(int argc, char *argv[]) {
  Solution solu;
  return 0;
}
