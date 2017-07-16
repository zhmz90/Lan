/* Copyright 2017 Lanting Guo */
/** 190. Reverse Bits
    
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

*/
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using string = std::string;

class Solution {
 public:
  // 6 0000 0110
    uint32_t reverseBits(uint32_t n) {
      uint32_t ret = 0;
      uint32_t pos = 0;
      while ( pos < 32) {
        ret += (n & 1)*pow(2, 31-pos);
        n = n >> 1;
        pos++;
      }
      return ret;
    }
};


int main(int argc, char *argv[]) {
  Solution solu;
  std::cout<< solu.reverseBits(43261596) << '\n';
  return 0;
}
