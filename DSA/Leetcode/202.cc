/* Copyright 2017 Lanting Guo */
/** 202. Happy Number
    
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>

using string = std::string;

class Solution {
 public:
    bool isHappy(int n) {
      if (n == 1) return true;
      //  for (auto v: nums) std::cout << v; std::cout<<std::endl;
      if (nums.find(n) != nums.end()) return false;
      nums.insert(n);
      int new_n = 0;
      while ( n > 0 ) {
        new_n += (n % 10) * (n % 10);
        n = n / 10;
      }
      //  std::cout << new_n << std::endl;
      return isHappy(new_n);
    }
  Solution(): nums{} {}
 private:
  std::set<int> nums;
};

int main(int argc, char *argv[]) {
  Solution solu;
  bool ret = solu.isHappy(3);
  std::cout << ret << std::endl;
  return 0;
}
