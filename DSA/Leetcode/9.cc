/**
9. Palindrome Number

Determine whether an integer is a palindrome. Do this without extra space.

 */

#include <iostream>
#include <limits>

using namespace std;

class Solution {
 public:
  // 1 2 4    if  x / 10 == 0 return true
  // 212 123  
  bool isPalindrome(int x) {
    if (x<0) return false;
    if (x/10==0) return true;
    if (x%10==0) return false;
    int div = x, right = 0;
    int mod = x % 10;
    int prev_right = 0;
    int num_pos = 0;
    while (div != 0){//not odd
      num_pos++;
      prev_right = right;
      right = right * 10 + mod;
      if (right<prev_right) return false;
      div = div / 10;
      if (right == div) return true;
      //cout<<div<<"--"<<right<<endl;
      mod = div % 10;
    }
    if (num_pos % 2 == 0) return false;
    div=x,right=0,mod=x%10;

    int prev_div = 0;
    prev_right=0;
    while (div != 0){//odd
      prev_right=right;
      right = right * 10 + mod;
      if (right < prev_right) return false;
      prev_div = div;
      div = div / 10;
      //cout<<div<<"--"<<prev_div<<"--"<<right<<"--"<<prev_right<<endl;
      if (right == prev_div) return true; // 212  21-2 2-21  100-0 10-0 1-0  101-0 10-1 1-10 

      mod = div % 10;
    }
    return false;
  }
};


int main(){
  Solution solu;
  int n = 100;
  cout<<numeric_limits<int>::min()<<endl;
  cout<<"n:"<<n<<endl;
  cout<<solu.isPalindrome(n)<<endl;
  
  return 0;
}
