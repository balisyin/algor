/** balis 20190818 
 * Shopee的办公室（二）
 * 牛客网上，办公室员工绕开老板进入工位的方法数，典型DP问题  **/

#include<iostream>
using namespace std;

long loc[1000][1000];

int main() {
    int x, y, n;
    cin >> x >> y >> n;
    int x1, y1;
    while(n--) {
        cin >> x1 >> y1;
        loc[x1][y1] = -1;
    }  

    for(auto i= 0; i<= x; i++) {
        for (auto j = 0; j <= y; j++) {
            if (loc[i][j] == -1) {
                continue;
            }
            if(i == 0 && j == 0) {
                loc[i][j] = 1;
            } else if(i == 0) {
                loc[i][j] = max(long(0),loc[i][j-1]);
            } else if (j == 0){   
                loc[i][j] = max(long(0),loc[i-1][j]);
            } else {
                loc[i][j] = max(long(0),loc[i-1][j]) + max(long(0),loc[i][j-1]);
            }
            //cout << i << j << loc[i][j] << endl;  
        }
    }

    cout << loc[x][y] << endl;
    return 0;  
} 
