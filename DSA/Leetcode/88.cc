/**88. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

#include <iostream>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> tmp;
    for (auto i=0;i<m;i++){
      tmp.push_back(nums1[i]);
    }
    auto iter1=tmp.begin(),iter2=nums2.begin(),iter=nums1.begin();
    auto end1 = tmp.end(), end2 = nums2.end();
    while (iter1!=end1 || iter2!=end2){
      if (iter1==end1) {*iter++=*iter2++; continue;}
      if (iter2==end2) {*iter++=*iter1++; continue;}
      if (*iter1<*iter2) *iter++ = *iter1++; else *iter++ = *iter2++;
    }
  }
};

int main(){
  Solution solu;
  solu.merge(nums1, m, nums2, n);
  
  return 0;
}
