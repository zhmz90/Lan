/** 66. Plus One
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> ret;
    int flow=1, digit=0;
    for (auto iter=digits.rbegin(), end=digits.rend(); iter!=end; iter++){
      digit = *iter + flow;
      if (digit - 10 >= 0){
        digit -= 10;
        flow = 1;
      }else {
        flow = 0;
      }
      ret.insert(ret.begin(), digit);
    }
    if (flow == 1) ret.insert(ret.begin(), flow);
    return ret;
  }
};

int main(){
  vector<int> v{1,2,3}, ret;
  Solution solu;
  ret = solu.plusOne(v);
  for_each(ret.begin(), ret.end(), [=](int n){cout<<n<<" ";});
  return 0;
}
