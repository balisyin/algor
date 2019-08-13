/** balis 20190209  **/

#include<bits/stdc++.h>
using namespace std;
#define LEN 50000
void swap(int& m, int& n){int tmp = m; m = n; n = tmp;}

///HEAP SORT
void heapAdjust(int arr[], int n){
    i = 0;
    while(i < n){
        int kidL = i<<1 + 1;
        int kidR = kidL + 1;
        int smaller = i;
        if(kidL < n && arr[kidL] < arr[smaller]){
            smaller = kidL;
        }
        if(kidR < n && arr[kidR] < arr[smaller]){
            smaller = kidR;
        }
        if(smaller != i){
            swap(arr[i], arr[smaller]);
            i = smaller;
        }
    }

    return;
}

void heapSort(int arr[], int n) {
    for(int i = 0; i < (n >> 1); ++i)
        heapAdjust(&arr[i], n)

    for(int j = n -1; j > 1; --j){
        swap(arr[0], arr[j]);
        heapAdjust(arr, j-1);
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
