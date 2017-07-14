// copyright 2017 Lanting Guo

/** 167. Two Sum II - Input array is sorted

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2    

 */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
 public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      vector<int> inds;
      int N = numbers.size();
      int left = 0, right = N-1;
      while (left < N && right >= 0) {
        /*
        if (numbers[right] > target) {
         right--;
         continue;
         }*/
        // right < target
        if (numbers[right] + numbers[left] == target ) {
          return {left+1, right+1};
        }        
        if (numbers[right] + numbers[left] < target ) {
          left++;
        }
        if (numbers[right] + numbers[left] > target ) {
          right--;
          left = 0;
        }
      }
    }
};

int main(int argc, char *argv[]) {
  
  return 0;
}

