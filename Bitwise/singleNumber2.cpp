/** balis 20190209  
 * 查找出现1次到数字，其他都出现2次   **/



//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
using namespace std;

//BW1 get the number show 1time, others show 3times
int the1times(int arr[], int n){
    int onetime = 0;
    
    for(int i = 0; i < n; ++i){
        onetime ^= arr[i];
    }
    return onetime;
}





int main(int arg, char* args[]){
    int arr[] = {4, 6, 9, 7, 7, 9, 4};
    cout << "1 times number is: " << the1times(arr, sizeof(arr)/sizeof(int)) << endl;
    getchar();
    return 0;
}