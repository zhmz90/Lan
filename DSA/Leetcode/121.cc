/** 121. Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int buy=0,sell=0;
    if (prices.size() <= 1) return 0;
    buy = prices[0], sell = buy;
    vector<int> profits{};
    for (auto iter=prices.begin()+1,end=prices.end(); iter!=end; iter++){
      if (*iter < buy) {
        profits.push_back(sell-buy);
        buy = *iter;
        sell = *iter;
      }
      if (*iter > sell) sell = *iter;
    }
    profits.push_back(sell-buy);
    //    for (auto p: profits) cout<<p<<" "; cout<<endl;
    return *max_element(profits.begin(),profits.end());
  }
};

int main(){
  Solution solu;
  vector<int> prices{7,1,5,3,6,4};
  for (auto p: prices) cout<<p<<" "; cout<<endl;
  cout<<solu.maxProfit(prices)<<endl;
  return 0;
}
