/* Copyright 2017 Lanting Guo */
/** 643. Maximum Average Subarray I
    
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using string = std::string;

class Solution {
 public:
  double findMaxAverage(std::vector<int>& nums, int k) {
      double sum = 0, max = 0;
      int len = nums.size(), i = 0;
      while ( i < k ) sum += nums[i++]; max = sum;
      while ( i < len ) {
        sum = sum + nums[i] - nums[i-k];
        if (sum > max) max = sum;
        i++;
      }
      return max/k;
    }
};

int main(int argc, char *argv[]) {
  Solution solu;
  std::vector<int> v{1, 12, -5, -6, 50, 3};
  std::cout<< solu.findMaxAverage(v, 4) << '\n';
  return 0;
}
