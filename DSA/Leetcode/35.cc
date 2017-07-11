/** 35. Search Insert Position
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    size_t len = nums.size();
    for (auto i=0; i<len; i++){
      if (nums[i]>=target) return i;
    }
    return len;
  }
};


int main(){
  Solution solu;
  vector<int> nums{1,3,5,6};
  int target=5;
  cout<<solu.searchInsert(nums, target)<<endl;

  return 0;
}
