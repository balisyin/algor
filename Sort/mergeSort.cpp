/** balis 20190209  **/

#include<bits/stdc++.h>
using namespace std;
#define LEN 50000
void swap(int& m, int& n){int tmp = m; m = n; n = tmp;}

///MERGE SORT
void mergeSort(int arr[], int l, int r){
    int tmp[r-l];
    int mid = (r-l) > 1;
    if(mid > l){
        mergeSort(arr, l, mid);
    }
    if((mid+1) < r){
        mergeSort(arr, mid+1, r);
    }
    int i = l;
    int j = r;
    int k = 0;

    while(i<l && j<r){
        if(arr[i] < arr[j]){
            tmp[k++] = arr[i++];
        } else{
            tmp[k++] = arr[j++];
        }
    }
    while(i < l){
        tmp[k++] = arr[i++];
    }
    while(j < r){
        tmp[k++] = arr[j++];
    }

    for(int index = 0; index < k; ++index){
        arr[l+index] = tmp[index];
    }
    return;
}


／*************main****************／
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
        //cout << arr[j] << endl;

    return 0;
}
