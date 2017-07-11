/** 26. Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <=1) return nums.size();
    auto iter=nums.begin(),last=nums.begin(),end=nums.end();
    while (iter!=end){
      if (*iter != *last) *(++last) = *iter;
      iter++;
    }
    return last-nums.begin()+1;
  }
};

int main(){
  Solution solu;
  /*
  for (auto& v: {{1,2,3},{0},{}}){
    cout<<solu.removeDuplicates(v)<<endl;
    }*/
  vector<int> v={};
  cout<<solu.removeDuplicates(v)<<endl;
  return 0;
}
