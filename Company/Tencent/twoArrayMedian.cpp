//两个有序数组求中位数，时间复杂度log(m+n)
#include<iostream>

using namespace std;


int main() {
    int m= 6;
    int n= 30;
    int arr1[m];
    int arr2[n];

    for(int i = 0; i<m; i++) {
        arr1[i] = i;
    }
    for(int i = 0; i<n; i++) {
        arr2[i] = 100+i;
    }
    for(int i = 0; i<m; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for(int i = 0; i<n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;


    int l_m = 0;
    int r_m = m-1;
    int l_n = 0;
    int r_n = n-1;
    int mid;

    while(l_m < r_m && l_n < r_n) {
        int half_m = (l_m+r_m) >> 1;
        int half_n = (l_n+r_n) >> 1;
        if (arr1[half_m] < arr2[half_n]) {
            l_m = half_m + 1;
            r_n = half_n - 1;
        } else {
            r_m = half_m - 1;
            l_n = half_n + 1;
        }
        cout << "balis" << endl;
    }
    cout << l_m << " m " << r_m << endl;
    cout << l_n << " n " << r_n << endl;
    if(l_m < r_m) {
        cout << l_m << " m " << r_m << endl;
        mid = arr1[(l_m+r_m)>>1];
    } else {
        cout << l_n << " n " << r_n << endl;
        mid = arr2[(l_n+r_n)>>1];
    }
    cout << mid << endl;


    return 0;
}