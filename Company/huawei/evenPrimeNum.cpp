/** balis 20200217 **/
/*输入一个偶数，求两个素数之和等于该偶数的最接近素数对*/
/*
lease input one even num:
34
17 17
*/


//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
using namespace std;

bool isPrime(int num) {
    for (auto i=2; i < num; i++) {
        if (num %i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "please input one even num:" << endl;
    int num;
    cin >> num;
    int half = num >> 1;
    for(auto i = half; i > 0; i--) {
        if (isPrime(i) && isPrime(num-i)) {
            cout << i << " " << num-i << endl;
            return 0;
        }
    }

    return 0;
}