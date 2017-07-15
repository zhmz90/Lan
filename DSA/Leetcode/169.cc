// copyright 2017 Lanting Guo

/** 169. Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

 */

#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int bound = nums.size() / 2;
    unordered_map<int, int> num_count;
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      if (num_count.find(*it) != num_count.end())
        num_count[*it] += 1;
      else
        num_count[*it] = 1;
    }
    int majority, max_cout = 0;
    for (auto p : num_count) {
      //std::cout << p.first << p.second << '\n';
      if (p.second > max_cout) {
        majority = p.first;
        max_cout = p.second;
      }
    }
    if (max_cout > bound)
      return majority;
  }
};

int main(int argc, char *argv[]) {
  Solution solu;
  vector<int> nums{1, 2, 2, 2, 2, 2, 4, 4};
  std::cout << solu.majorityElement(nums) << std::endl;
  return 0;
}

