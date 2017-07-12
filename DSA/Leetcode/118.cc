/**118. Pascal's Triangle
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
   
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
  vector<vector<int>> generate(int numRows) {
    if (numRows<1) return {};
    if (numRows==1) return {{1}};
    vector<vector<int>> ret={{1}};
    while (--numRows>=1){
      ret.push_back(nextRow(ret.back()));
    }
    return ret;
  }
};

int main(){
  Solution solu;
  auto ret = solu.generate(5);
  for (auto v: ret){
    for (auto n: v){
      cout<<n<<" ";
    }
    cout<<endl;
  }
  return 0;
}
