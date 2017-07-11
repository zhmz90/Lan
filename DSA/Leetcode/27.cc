/**
   27. Remove Element
   
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    auto iter=nums.begin(),last=nums.begin(),end=nums.end();
    while (iter != end){
      if (*iter != val) {
        *last = *iter;
        last++;
      }
      iter++;
    }
    nums.resize(last-nums.begin());
    return last-nums.begin();
  }
};

int main(){
  Solution solu;
  vector<int> nums{0,1,2,2,3,6,8,2,4};
  int val = 2;
  nums ={};
  solu.removeElement(nums,val);
  for (auto n: nums){
    cout<<n<<" ";
  }
  cout<<endl;
  
  return 0;
}
