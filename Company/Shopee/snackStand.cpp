/** balis 20190818 
 * Shopee的零食柜 牛客网上，典型DP问题  **/

#include<iostream>
#include<vector>

using namespace std;

void getMaxPacePerMinute(long n, long m, long bottom, long ceil, vector<long> &musics) {
    int maxPace = 0;
    while (bottom <= ceil) {
        maxPace = bottom + ((ceil - bottom) >> 1);
        cout << "maxpace:" << maxPace <<" " <<bottom <<" " << ceil << endl;
        auto num = 0;
        for(auto i = 0; i < n;) {
            auto sum = 0;
            while(i < n && (sum + musics[i] <= maxPace)) {
                sum += musics[i++];
            }
            num++;
            if (num > m) {
                break;
            }
            
        }
        cout << "m ,num:" << m << " " << num << endl;
        if (num <= m) {
            ceil = maxPace -1;
        } else {
            bottom = maxPace + 1;
        }
        
    }
    cout << maxPace << endl;

    return;
}

////test
/**
8 5
6 5 6 7 6 6 3 1
 */


int main() {

    long n, m; //音符数，分钟数
    long bottom = 0, ceil = 0; //单分钟最小步数，最大步数
    cin >> n >> m;
    vector<long> musics(n, 0);
    for(auto i = 0; i < n; i++) {
        cin >> musics[i];
        bottom = max(bottom, musics[i]);
        ceil += musics[i];
    }
    
    //cout << n << m << bottom << ceil << endl;
    getMaxPacePerMinute(n, m, bottom, ceil, musics);

    return 0;
}