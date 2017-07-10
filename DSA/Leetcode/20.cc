/** 20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <stack>
#include <typeinfo>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> pstack;
    bool flag = true;
    char topc,cc;
    for (auto c: s){
      if (pstack.empty() || '(' == c || '[' == c || '{' == c){
        pstack.push(c);
        continue;
      }
      topc = pstack.top();
      cc = getComplement(c);
      if (topc == cc)
        pstack.pop();
      else
        return false;//pstack.push(c);
    }
    if (!pstack.empty()) flag = false;
    
    return flag;
  }
  char getComplement(char c){
    switch(c){
      case ')': return '(';
      case ']': return '[';
      case '}': return '{';
    }
  }
};


int main(){
  string str;
  Solution solu;
  for (auto str: {"()[]","(]"}){
    cout<<str<<"--"<<solu.isValid(str)<<endl;
  }
  
  return 0;
}
