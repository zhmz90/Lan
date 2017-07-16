/* Copyright 2017 Lanting Guo */
/** 172. Factorial Trailing Zeroes

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>


using string = std::string;

class Solution {
 public:
    int trailingZeroes(int n) {
      if ( n < 5 ) return 0;
      int count = 0;
      while ( (n /= 5) > 0)
        count += n;
      return count;
    }
};

/*
 5 1
 5*2 2
 5*3 3
 5*4 4
 5*5 4+2=6
 5*6 7
 5*7 8
 5*8 9
 5*9 10
 5*5*2 10+2=12
 5*11 13
 5*12 14
 5*13 15
 5*14 16
 5*5*3 16+2 = 18
 5*16 19
 5*5*5 
 
 */

int main(int argc, char *argv[]) {
  Solution solu;
  std::cout << solu.trailingZeroes(24) << "\n";
  std::cout << solu.trailingZeroes(25) << "\n";
  std::cout << solu.trailingZeroes(50) << "\n";
  std::cout << solu.trailingZeroes(125) << "\n";
  return 0;
}
