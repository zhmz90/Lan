/* Copyright 2017 Lanting Guo */
/** 268. Missing Number
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?


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
    int missingNumber(vector<int>& nums) {
      int sum = 0;
      int len = nums.size();
      for (auto i : nums) sum += i;
      return (1+len)*len/2 - sum;
    }
};


int main(int argc, char *argv[]) {
  Solution solu;
  return 0;
}
