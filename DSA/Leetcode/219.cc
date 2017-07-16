/* Copyright 2017 Lanting Guo */
/** 219. Contains Duplicate II

Given an array of integers and an integer k,
find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and
the absolute difference between i and j is at most k.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using string = std::string;

bool compare(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first < p2.first) return true;
  if (p1.first > p2.first) return false;
  if (p1.second < p2.second)
    return true;
  else
    return false;
}
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if (nums.size() <= 1) return false;
    vector<pair<int, int>> data;
    int N = nums.size();
    for (auto i = 0; i < N; i++) {
      data.push_back(make_pair(nums[i], i));
    }
    sort(data.begin(), data.end(), compare);
    for (auto it = data.begin(); it != data.end()-1; ++it) {
      if (it->first == (it+1)->first &&
          abs(it->second - (it+1)->second) <= k)
        return true;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution solu;
  return 0;
}
