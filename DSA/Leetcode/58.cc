/** 58. Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int len=0;
    if (s.length()==0) return len;
    auto iter=s.rbegin(),end=s.rend();
    while (iter != end){
      if (*iter++ == ' '){ if (len == 0) continue; else break;}
      len++;
    }
    return len;
  }
};

int main(){
  string test{"Guo Lan Ting"};
  Solution solu;
  cout<<solu.lengthOfLastWord(test)<<endl;
  
  return 0;
}
