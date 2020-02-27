/*20200221 balis [Leetcode] 238. Product of Array Except Self
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

#include<iostream>
#include<vector>

using namespace std;
vector<int> productExceptSelf(vector<int> &vec);

int main(){
    int total, answer = 0;
    cin >> total;
    vector<int> ret, vec = vector<int>(total, 0);
    

     for(int i=0; i<total; i++) {
        cin >> vec[i];
    }

    ret = productExceptSelf(vec);

    for(int i= 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;

     return 0;
}

vector<int> productExceptSelf(vector<int> &vec) {
    vector<int> ret = vector<int>(vec.size(), 1);
    vector<int> rev = vector<int>(vec.size(), 1);
    for(int i=1; i<vec.size(); i++) {
       ret[i] = vec[i-1]*ret[i-1];
    }
    for(int j=vec.size()-2; j>=0; j--) {
        rev[j] = rev[j+1]*vec[j+1];
    }

    for(int k=0; k <rev.size(); k++) {
        ret[k] *= rev[k];
    }

    return ret;

}