/** 28. Implement strStr()

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 */

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle){
    int index=-1;
    size_t indn=0,lenn=needle.length();
    if (haystack.length()<lenn) return index;
    for (size_t indh=0,lenh=haystack.length(); indh!=lenh-lenn+1; indh++){
      while (haystack[indh] == needle[indn] && indn<lenn){indh++;indn++;}
      if (indn == lenn) return indh-lenn;
      indh -= indn;
      indn  = 0;
    }
    return index;
  }
};


int main(){
  Solution solu;
  string needle{"lan"};
  string haystack{"guolanting"};
  cout<<solu.strStr(haystack,needle)<<endl;
  //  cout<<needle[0]<<endl;
  return 0;
}
