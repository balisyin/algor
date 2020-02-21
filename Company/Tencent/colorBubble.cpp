/* balisyin 20190221 滑动窗口问题
包含所以非零数字，且连续最短
输入 12 5
2 5 3 1 3 2 4 1 0 5 4 3 
2 [5 3 1 3 2 4] 1 0 5 4 3 
2 5 3 1 【3 2 4 1 0 5】 4 3 
输出 6
*/

#include<iostream>
#include<map>
using namespace std;

int main() {
    int total, kind;
    cin >> total >> kind;
    int arr[total];
    map<int, int> count;
    int color = 0;
    int res = total +1;
    for(int i=0; i< total; i++) {
        cin >> arr[i];
        count[i] = 0; 
    }

    for(int i=0, j = 0; i < total; i++) {
        if(arr[i] && !count[arr[i]]) {
            color++;
        }
        cout << "clolor" << arr[i] << color << endl;

        count[arr[i]]++;

        if (color == kind) {
            while(!arr[j] || count[arr[j]] > 1) {
                j++;
                count[arr[j]]--;
            }
            res = min(res, i-j+1);
        }
    }

    if(res > total) {
        res = -1;
    }


    cout << res << endl;;

    return 0;
}

 

