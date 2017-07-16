/* Copyright 2017 Lanting Guo */
/** 217. Contains Duplicate

Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array,
and it should return false if every element is distinct.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using string = std::string;


class Solution {
 public:
    bool containsDuplicate(vector<int>& nums) {
      if (nums.size() <= 1) return false;
      sort(nums.begin(),nums.end());
      for (auto it = nums.begin(); it != nums.end()-1; ++it) {
        if (*it == *(it+1)) return true;
      }
      return false;
    }
};

int main(int argc, char *argv[]) {
  Solution solu;
  return 0;
}
