/** 119. Pascal's Triangle II
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> nextRow(vector<int> nums){
    vector<int> new_row{1};
    nums.insert(nums.end(),0);
    for (auto iter=nums.begin(),end=nums.end()-1; iter!=end; iter++){
      new_row.push_back(*iter+*(iter+1));
    }
    return new_row;
  }  
  vector<int> getRow(int rowIndex) {
    vector<int> ret={1};
    if (rowIndex == 0) return ret;
    while (--rowIndex>=0){
      ret = nextRow(ret);
    }
    return ret;
  }
};

int main(){
  Solution solu;
  auto ret = solu.getRow(5);

  return 0;
}
