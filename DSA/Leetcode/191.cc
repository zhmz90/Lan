/* Copyright 2017 Lanting Guo */
/** 191. Number of 1 Bits
    
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using string = std::string;

class Solution {
 public:
    int hammingWeight(uint32_t n) {
      int count = 0;
      while (n > 0) {
        if ( (n&1) == 1) count += 1;
        n = n >> 1;
      }
      return count;
    }
};


int main(int argc, char *argv[]) {
  Solution solu;
  std::cout << solu.hammingWeight(11) << '\n';
  return 0;
}
