// copyright 2017 Lanting Guo
/** 125. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

class Solution {
 public:
  template <typename T>
  char nextChar(T iter, T end) {
    char c;
    while (iter != end) {
      c = *iter++;
      if ('A' <= c&&c <='Z') return c-'A'+'a';
      if (('a' <=c&&c <='z') || ('0' <=c&&c <='9')) {
        return c;
      }
    }
    return '@';
  }
  bool isPalindrome(std::string s) {
    auto forward_iter = s.begin(), forward_end = s.end();
    auto backward_iter = s.rbegin(), backward_end = s.rend();
    int len = s.length(), half_len = len/2, i = 0;
    char fc, bc;
    while (++i <= half_len) {
      fc = nextChar<std::string::iterator&>(forward_iter, forward_end);
      bc = nextChar<std::string::reverse_iterator&>(backward_iter,
                                                    backward_end);
      if (fc != bc) return false;
    }
    return true;
  }
};

int main() {
  std::string s = "A man, a plan, a canal: Panama";
  Solution solu;
  bool ret = solu.isPalindrome(s);
  std::cout<< ret << std::endl;
  return 0;
}
