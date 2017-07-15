/* Copyright 2017 Lanting Guo */
/** 171. Excel Sheet Column Number
    
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

*/
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using string = std::string;


class Solution {
 public:
    int titleToNumber(string s) {
      int ret = 0;
      int i = 0, len = s.length();
      while ( len-- > 0 ) {
        ret += (s[len] - 'A' + 1) * pow(26, i++);
      }
      return ret;
    }
};

int main(int argc, char *argv[]) {
Solution solu;
std::cout << solu.titleToNumber("AB") << "\n";
return 0;
}
