/** 14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
 */

#include <iostream>
#include <vector>
#include <string>
//#include 

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string prefix{};
    if (strs.size() == 0) return prefix;
    
    vector<pair<string::iterator,string::iterator>> iter_pairs;
    for (auto& str: strs){
      iter_pairs.push_back({str.begin(),str.end()});
    }
    while (true){
      char curr_char = *iter_pairs[0].first;
      for (auto& iter_pair: iter_pairs){
        if (  iter_pair.first  == iter_pair.second ||
              *iter_pair.first != curr_char){
          return prefix;
        }
        iter_pair.first++;
      }
      prefix += curr_char;
      //cout<<prefix<<endl;
    }
    return prefix;
  }
};


int main(){
  Solution solu;
  string prefix;
  vector<vector<string>> vvstr{{"guo","gu","gud"},{"guolanting","guoan","guolanlan"},{"AGW","A-"}};
  for (auto& strs: vvstr){
    prefix = solu.longestCommonPrefix(strs);
    for (auto str: strs)
      cout<<str<<" ";
    cout<<"-- "<<prefix<<endl;
  }
  return 0;
}
