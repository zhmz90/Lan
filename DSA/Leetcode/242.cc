/* Copyright 2017 Lanting Guo */
/** 242. Valid Anagram
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <memory>

using std::string;
using std::vector;
using std::endl;
using std::cin;
using std::shared_ptr;
using std::make_shared;


class Solution {
 public:
    bool isAnagram(string s, string t) {
      std::sort(s.begin(), s.end());
      std::sort(t.begin(), t.end());
      return s == t;
    }
};

int main(int argc, char *argv[]) {
  Solution solu;
  string str = "anagram";
  return 0;
}
