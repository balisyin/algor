/** balis 20190209  **/

///#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#define LEN 50
using namespace std;

void swap(int& m, int& n){int tmp = m; m = n; n = tmp;}

///QUICK SORT
int partition(int arr[], int l, int r){
    int part = arr[r];
    int j = l - 1;
    for(int i = l; i < r; ++i){
        if(arr[i] < part){
            ++j;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j+1], arr[r]);
    return j+1;
}
void quickSort(int arr[], int l, int r){
    int mid = partition(arr, l, r);
    if(mid - 1 > l)
        quickSort(arr, l, mid - 1);
    if(mid < r - 1)
        quickSort(arr, mid+1, r);
    return;
}


int main(int arg, char* args[]) {

    //int* arr = new int[LEN];
    int arr[LEN];
    for(int i = 0; i < LEN; ++i)
        arr[i] = LEN - i;
    auto begin = chrono::system_clock::now().time_since_epoch() / chrono::seconds(1);
    quickSort(arr, 0, LEN-1);
    auto end = chrono::system_clock::now().time_since_epoch() / chrono::seconds(1);
    cout << "sort " << LEN << " numbers use " << end - begin << " ms" << endl;

    for(int j = 0; j < LEN; ++j)
        cout << arr[j] << endl;

    return 0;
}
