/* Copyright 2017 Lanting Guo */
/** Count inversions in an given array,
    which is pa2 of stanford algorithms coursera course.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using std::string;
using std::vector;

uint64_t CountSplitInversion(vector<int>::iterator begin,
                        vector<int>::iterator mid,
                        vector<int>::iterator end) {
  vector<int> left;
  for (auto it = begin; it != mid; it++) {
    left.push_back(*it);
  }
  /*
  std::cout << "left: ";
  for (auto it = left.begin(); it != left.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
  std::cout << "right: ";
  for (auto it = mid; it != end; ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
  */
  uint64_t count = 0;
  auto left_it = left.begin(), right_it = mid, new_it = begin;
  while (left_it != left.end()) {
    if (right_it == end || (right_it != end && *left_it < *right_it)) {
      *new_it = *left_it;
      count += (new_it - begin) - (left_it - left.begin());
      // std::cout << *left_it << "--" << count << std::endl;
      left_it++, new_it++;
    }
    if (right_it != end && *right_it < *left_it) {
      *new_it++ = *right_it++;
    }
  }

  // std::cout << "count: " << count << std::endl;
  return count;
}
uint64_t CountInversion(vector<int>::iterator begin,
                        vector<int>::iterator end) {
  auto len = end - begin;
  if (len <= 1) return 0;

  auto mid  = len / 2;
  auto left  = CountInversion(begin, begin + mid);
  auto right = CountInversion(begin + mid, end);
  auto cross = CountSplitInversion(begin, begin+mid, end);

  return left + right + cross;
}

int main(int argc, char *argv[]) {
  vector<int> nums = {};

  string row;
  while (!std::getline(std::cin, row).eof()) {
    nums.push_back(std::stoi(row));
  }

  auto num_inv = CountInversion(nums.begin(), nums.end());
  std::cout << nums.size() << '\n';
  /*
  for (auto it = nums.begin(); it != nums.end(); ++it) {
    std::cout << *it << " ";
  }
  */
  // std::cout << std::endl;
  std::cout << num_inv << '\n';
  return 0;
}
