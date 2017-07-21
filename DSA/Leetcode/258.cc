/* Copyright 2017 Lanting Guo */
/** 258. Add Digits
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

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
  int addDigits(int num) {
    if (num == 0) return 0;
    int ret = num % 9;
    if (ret == 0) return 9;
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution solu;
  return 0;
}
