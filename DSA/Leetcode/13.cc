/**
   13. Roman to Integer

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

 */

#include <iostream>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    if (s.length()==0) return 0;
    if (s.length() == 1) return getInt(s.begin());
    auto prev=s.begin(),curr=s.begin()+1,end=s.end();
    int ret=0;
    int prev_num=0,curr_num=0;
    prev_num = getInt(prev);
    ret = prev_num;
    while (curr != end){
      //      cout<<ret<<"--";
      curr_num = getInt(curr);
      if (prev_num < curr_num){
        ret -= prev_num;
        ret += curr_num-prev_num;
      }
      else{
        ret += curr_num;
      }
      prev_num = curr_num;
      curr++;
      
    }
    return ret;
  }
  
  int getInt(string::iterator p ){
    auto got = map.find(*p);
    if (got != map.end())
      return got->second;
    throw invalid_argument("string not in roman list");
    return 0;
  }
  Solution():map{{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}}}{}
 private:
  const unordered_map<char, int> map;
};


int main(){
  Solution solu;
  string str;
  for (auto str: {"I","V","IV","DC","MCMXCVI"}){// 1000 + 1000-100 + 100-10+5+1
    int ret = solu.romanToInt(str);
    cout<<"str:"<<str<<"--"<<"Int:"<<ret<<endl;
  }
  return 0;
}
