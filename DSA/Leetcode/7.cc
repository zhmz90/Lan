/**
   7. Reverse Integer
   Reverse digits of an integer.

   Example1: x = 123, return 321
   Example2: x = -123, return -321
*/

#include <iostream>
#include <limits>

using namespace std;

class Solution {
 public:
  int revPos(int x){ //
    //cout<<x<<endl;
    int div = x, mod = 0, addmod=0;
    int tmp_mod=0;
    while (div != 0){
      addmod = div % 10; //
      tmp_mod = mod;
      for (int i=0; i<9; i++){
        mod += tmp_mod;
        //cout<<mod<<"--";
        if (mod < 0){
          if (mod == int_min && i==9 && addmod ==0 && div/10== 0 ) return int_min;
          return 0; 
        }
      }
      mod += addmod;
      div /= 10;
      //cout<<mod<<endl;
      if (mod < 0){
        if (mod == int_min && div == 0) return int_min;
        return 0; 
      }
    }
    return mod;
  }
  int reverse(int x){
    int ret = 0;
    if (x == int_min) return 0;
    if (x>=0){
      ret = revPos(x);
      if (ret < 0) return 0;
      return ret;
    }
    else{
      ret = revPos(-1*x);
      if (ret<0) return ret;
      return -1*ret;
    }
  }
  Solution():int_max{numeric_limits<int>::max()},int_min{numeric_limits<int>::min()},theta{(int_max-9)/10}{}
 private:
  const int int_max;
  const int int_min;
  const int theta;
};

int main(){
  Solution s;
  int t = 1534236469;
  cout<<"t: "<<t<<endl;
  cout<<"-t:"<<-1*t<<endl;
  
  int ret = s.reverse(t);
  cout<<t<<" :"<<ret<<endl;

  return 0;
}
