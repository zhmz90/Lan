/** 67. Add Binary
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  char add(char a, char b, int& flow){
    if (a == '1'){
      if (b == '1'){// '1' '1'
        if (flow == 0){flow=1; return '0';}else {flow=1; return '1';}
      }else {//'1' '0'
        if (flow == 0){flow=0; return '1';}else {flow=1; return '0';}
      }
    }else{
      if (b == '1'){// '0' '1'
        if (flow == 0){flow=0; return '1';}else {flow=1; return '0';}
      }else {//'0' '0'
        if (flow == 0){flow=0; return '0';}else {flow=0; return '1';}
      }      
    }
  }
  string add(string a, string b, int& flow){ // a.length()== b.length()
    string c;
    int len=a.length();
    for (int i=len-1; i>=0; i--){
      c = add(a[i],b[i], flow) + c;
    }
    // cout<<"c in the add string:"<<c<<endl;
    //cout<<"flow add:"<<flow<<endl;
    return c;
  }
  string addBinary(string a, string b){
    string c = "";
    if (a.length() == 0 || b.length() == 0) return c;
    if (a.length() < b.length()){
      string tmp=a;
      a = b;
      b = tmp;
    }
    int flow=0;
    // len_a >= len_b
    int len_a = a.length(), len_b=b.length();
    c = add(a.substr(len_a-len_b), b, flow);
    //cout<<"c:"<<c<<endl;
    //cout<<"flow:"<<flow<<endl;
    //cout<<a<<" "<<b<<endl;
    for (int i=len_a-len_b-1; i>=0; i--){
      //      cout<<c<<endl;
      if (flow == 0){ c=a[i]+c; continue;}
      if (a[i] == '0'){
        c='1'+c;
        flow=0;
      }else{
        c='0'+c;
        flow=1;
      }
    }
    if (flow == 1) c='1'+c;
    //cout<<"final c:"<<c<<endl;
    return c;
  }
};

int main(){
  string a{"10"},b{"11"};
  Solution solu;
  cout<<solu.addBinary(a,b)<<endl;
  //cout<<stoi(a)<<endl;
  return 0;
}
