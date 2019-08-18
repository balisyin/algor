/** balis 20190818 
 * Shopee的物流中转站 牛客网上 **/
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<limits.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int xLeft = n-1, xRight = 0, yBottom = n-1, yCeil= 0;//边界
    vector<vector<int>> grid(n, vector<int>(n,0));
    multimap<int, int> house;

    for (auto i = 0; i< n; i++) {
        for (auto j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j]) {
                house.insert(make_pair(i, j));
                if (i < yBottom) yBottom = i;
                if (i > yCeil) yCeil = i;
                if (j < xLeft) xLeft = j;
                if (j > xRight) xRight = j;
            }
        }
    }

    //cout << yBottom << yCeil << xLeft << xRight << endl;
    int minLen = INT_MAX;
    for (auto i = 0; i <= n-1; i++) {
        for (auto j = 0; j <= n-1; j++) {
            int sum = 0;
            if(grid[i][j] == 0) {
                for (auto it = house.begin(); it != house.end(); it++) {
                sum += abs(i - it->first) + abs(j - it->second);
                //cout << i << " " << j << " sum:" << sum << endl;
                }
                minLen = min(sum, minLen);
            }
            
        }
    }
    if(minLen == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minLen << endl;
    }

    return 0;

}

/**举例输入
4
0 1 1 0
1 1 0 1
0 0 1 0
0 0 0 0
 */