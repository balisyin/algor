/*20200221 balis [Leetcode] 268. Missing Number
Given a non-empty array of integers, return the k most frequent elements.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> kv;
        priority_queue<pair<int, int>> que;
        vector<int> ret;
        for(auto i:nums) ++kv[i];
        for(auto it:kv) {
            que.push({it.second, it.first});
        }
        for(int i=0; i < k; i++) {
            ret.push_back(que.top().second);
            que.pop();
        }
        return ret;
    }
};