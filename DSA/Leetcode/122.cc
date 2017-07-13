/** 122. Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like
(ie, buy one and sell one share of the stock multiple times).
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size()<=1) return 0;
    vector<int> profits;
    auto iter=prices.begin(),end=prices.end();
    int buy = *iter, sell = *iter;
    while (++iter!=end){
      if (*iter < sell) profits.push_back(sell-buy),buy=*iter,sell=*iter;
      if (*iter > sell) sell = *iter;
    }
    profits.push_back(sell-buy);
    int sum=0;
    for (auto p: profits) if (p>0) sum+=p;
    return sum;
  }
};

int main(){
  Solution solu;
  vector<int> prices{7,1,5,3,6,4};
  for (auto p: prices) cout<<p<<" "; cout<<endl;
  cout<<solu.maxProfit(prices)<<endl;
  return 0;
}
