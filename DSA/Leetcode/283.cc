/* Copyright 2017 Lanting Guo */
/**　283. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <memory>
#include <typeinfo>

using std::string;
using std::vector;
using std::endl;
using std::cin;
using std::shared_ptr;
using std::make_shared;


class Solution {
 public:
    void moveZeroes(vector<int>& nums) {
      auto size = nums.size();
      if (size <= 1) return;
      int num_zero = 0;
      for (auto it = nums.begin(); it != nums.end(); ++it) {
        if (*it == 0) {
          num_zero += 1;
          continue;
        }
        *(it - num_zero) = *it;
      }
      while (num_zero > 0) {
        nums[size-num_zero] = 0;
        num_zero--;
      }
    }
};

int main(int argc, char *argv[]) {
  Solution solu;
  vector<int> v = {3,1,2,0,0,2,0,1};
  solu.moveZeroes(v);
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it;
  }
  std::cout << "\n";
  return 0;
}
