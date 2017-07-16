/* Copyright 2017 Lanting Guo */
/** 189. Rotate Array

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using string = std::string;

class Solution {
 public:
    void rotate(vector<int>& nums, int k) {
      int len = nums.size();
      vector<int> tmp(k);
      k = k % len;
      // move last k element to tmp vector
      for (int i = 0; i < k; i++) {
        tmp[i] = nums[len-k+i];
      }
      // shift k element in nums
      for (int i = len-1; i >= 0; i--) {
        nums[i] = nums[i-k];
      }
      // move tmp to head 
      for (auto i = 0; i < k; i++) {
        nums[i] = tmp[i];
      }
    }
};


int main(int argc, char *argv[]) {
Solution solu;
return 0;
}
