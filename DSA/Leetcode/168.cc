// copyright 2017 Lanting Guo

/** 168. Excel Sheet Column Title

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

 */

#include <iostream>
#include <string>

using std::string;

class Solution {
 public:
    string convertToTitle(int n) {
      string ret;
      int div = n;
      int mod = (div-1) % 26;
      while (div != 0) {
        //std::cout << ret << "--" << div << std::endl;
        ret.insert(0, 1, static_cast<char>('A' + mod));
        div = (div-1) / 26;
        mod = (div-1) % 26;
      }
      return ret;
    }
};

int main(int argc, char *argv[]) {
  //  std::cout << static_cast<char>('A'+1) << "\n";
  Solution solu;
  int n = 28;
  string ret = solu.convertToTitle(n);
  std::cout << ret << "\n";
  return 0;
}
