/* Copyright 2017 Lanting Guo */
/**


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


vector<int>::iterator partition(vector<int>::iterator pivot,
                                vector<int>::iterator begin,
                                vector<int>::iterator end) {
  std::swap(*pivot, *begin);
  auto it_i = begin + 1, it_j = begin + 1;
  while (it_j != end) {
    if (*it_j < *begin) {
      std::swap(*it_i++, *it_j);
    }
    it_j++;
  }
  std::swap(*(it_i-1), *begin);
  return it_i-1;
}

vector<int>::iterator chooseFirstpivot(vector<int>::iterator begin,
                                       vector<int>::iterator end) {
  return begin;
}
vector<int>::iterator chooseFinalpivot(vector<int>::iterator begin,
                                       vector<int>::iterator end) {
  return end-1;
}
vector<int>::iterator chooseMedianpivot(vector<int>::iterator begin,
                                       vector<int>::iterator end) {
  auto first = chooseFirstpivot(begin, end);
  auto last  = chooseFinalpivot(begin, end);
  // get mid point
  auto len = end - begin;
  vector<int>::iterator mid;
  if (len % 2 == 0)
    mid = begin + len / 2 - 1;
  else
    mid = begin + len / 2;

  // median of first, mid and final
  if (*first < *last  && *first > *mid)   return first;
  if (*first < *mid   && *first > *last)  return first;
  if (*last <  *first && *last  > *mid)   return last;
  if (*last <  *mid   && *last  > *first) return last;
  return mid;
}
int quicksort(vector<int>::iterator begin, vector<int>::iterator end) {
  int comparisons = 0;
  if (end - begin <= 1) return comparisons;
  auto pivot = chooseMedianpivot(begin, end);
  auto mid = partition(pivot, begin, end);
  comparisons += end - begin - 1;
  comparisons += quicksort(begin, mid);
  comparisons += quicksort(mid+1, end);

  return comparisons;
}

int main(int argc, char *argv[]) {
  vector<int> nums;
  string num;
  while (!getline(std::cin, num).eof()) {
    nums.push_back(std::stoi(num));
  }

  // nums = {3, 2, 1, 0, 5, 13, 11};
  auto c = quicksort(nums.begin(), nums.end());
  std::cout << c << "\n";
  for (auto it = nums.begin(); it != nums.end(); ++it) {
    // std::cout << *it;
  }
  std::cout << std::endl;
  return 0;
}
