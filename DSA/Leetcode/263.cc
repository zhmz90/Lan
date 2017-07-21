/* Copyright 2017 Lanting Guo */
/** 263. Ugly Number
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <memory>

using std::string;
using std::vector;
using std::endl;
using std::cin;
using std::shared_ptr;
using std::make_shared;


class Solution {
 public:
  bool isUgly(int num) {
    if (num <= 0)
      return false;
    if (num <= 6)
      return true;
    int i = 2;
    while (num > 1) {
      if (num % 2 == 0) {
        num = num / 2;
        continue;
      }
      if (num % 3 == 0) {
        num = num / 3;
        continue;
      }
      if (num % 5 == 0) {
        num = num / 5;
        continue;
      }
      return false;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution solu;
  std::cout << solu.isUgly(905391974) << '\n';
  return 0;
}
