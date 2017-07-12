/** 38. Count and Say

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"

 */

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    string str="1", tmp="";
    while (--n!=0){
      auto iter=str.begin(), end=str.end();
      tmp = "";
      int count=0;
      char target=*iter;
      while (iter!= end){//; iter++){
        if (*iter != target) {tmp += to_string(count)+target; target=*iter; count=0;}
        count++;
        iter++;
      }
      tmp += to_string(count) + target;
      str = tmp;
      //cout<<str<<endl;
    }
    return str;
  }
};

int main(){
  string test="12";
  Solution solu;
  cout<<solu.countAndSay(6)<<endl;
  return 0;
}
