/**
  3. Longest Substring Without Repeating Characters
  Given a string, find the length of the longest substring without repeating characters.

  Examples:
  Given "abcabcbb", the answer is "abc", which the length is 3.
  Given "bbbbb", the answer is "b", with the length of 1.
  Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;

typedef unsigned int UInt32;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() == 0) return 0;
    vector<size_t> lens = {};
    string substring = "";
    size_t ind = 0;
    for (auto c: s){
      ind = substring.find_last_of(c);
      if (string::npos != ind){ // not in substr
        lens.push_back(substring.length());
        substring = substring.substr(ind+1);
      }
      substring.push_back(c);
    }
    lens.push_back(substring.length());
    
    size_t tmp = 0;
    for (auto l: lens){
      if (l > tmp) tmp = l;
    }
    
    return (int)tmp;
  }
};


/*
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() == 0) return 0;
    size_t max = 0;
    string substr = "";
    for (auto c: s){
      size_t ind = substr.find_last_of(c);
      if (string::npos == ind) // not in substr
        substr.push_back(c);
      else {
        size_t l = substr.length();
        if (l > max) max = l;
        substr.push_back(c);
        substr = substr.substr(ind);
      }
    }

    return max;
  }
};
*/

int main(){
  string s = "test";
  cout<<s.length()<<endl;
  for (auto c: s)
    cout<<c<<endl;
  char a = 'A';
  s.push_back('B');
  cout<<s<<endl;
  size_t c = s.find_last_of('e');
  c = s.find_last_of('A');
  cout<<(c==string::npos)<<endl;
  cout<<s.substr(2)<<endl;
  cout<<"---------"<<endl;
  vector<UInt32> v = {};
  cout<<v.size()<<endl;
  v.push_back(1);
  v.push_back(10);
  for (auto e: v)
    cout<<e<<endl;
  cout<<"max_elem:"<<*std::max_element(v.begin(),v.end())<<endl;
  cout<<"---------"<<endl;
  Solution solu;
  string test = "abcabcbb";
  int l = solu.lengthOfLongestSubstring(test);
  cout<<test<<":"<<l<<endl;
  //"bbbbb" 1
  test = "abcabcbb";
  l = solu.lengthOfLongestSubstring(test);
  cout<<test<<":"<<l<<endl;
  //"pwwkew", the answer is "wke", with the length of 3
  test = "bpfbhmipx";
  l = solu.lengthOfLongestSubstring(test);
  cout<<test<<":"<<l<<endl;
  return 0;
}
