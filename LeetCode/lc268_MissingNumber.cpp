/*20200221 balis [Leetcode] 268. Missing Number
Given an array containing n distinct numbers taken from 0, 1, 2, …, n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

#include<iostream>
using namespace std;
int main(){
    int total, answer = 0;
    cin >> total;
    int nums[total-1];
    for(int i=0; i<total-1; i++) {
        cin >> nums[i];
        answer = answer ^ nums[i] ^ i;
        
    }

    answer = answer ^ (total-1);
    

    cout << answer << endl;
    return 0;
}