#include<iostream>
using namespace std;
int minShotForAllColor(int arr[], int len, int color) {
    //2 5 3 1 3 2 4 1 0 5 4 3
    //12 5
    int minShot = INT_MAX;
    
    for(auto i= 0; i < len; i++) {
        if ((len-i) < color) {
            break;
        }
        map<int,int> shot;
        for (auto j = i; j < len; j++) {
            shot[arr[i]]=1;
            if shot.size() == color {
                min = j-i;
                if min < minShot {
                    minShot = min;
                }
            }
        }
    }
    if (minShot ==INT_MAX) {
        return -1;
    }

    return minShot;
}