/* *
 * balisyin 20190816
 * min k number
 * */

//很大数据查找最小k个数。升序用大顶堆

#include<iostream>
using namespace std;

int heapAdjust(int arr[], int n) {
    int i = 0;
    int leftKid, rightKid;
    int big;
    while (i < n) {
        leftKid = i << 1 +1;
        rightKid = leftKid + 1;
        big = i;
        if (leftKid < n && arr[leftKid] > arr[big]) {
            big = leftKid;
        }
        if (rightKid < n && arr[rightKid] > arr[big]) {
            big = rightKid;
        }

        if (big != i) {
            swap(arr[i], arr[big]);
            i = big;
        }

    }




    int leftKid = 
}


int minKnumbers(int arr[], int tmp[], int k, int n) {
    for(int i = 0; i < k; i++) {
        tmp[i] = arr[i];
    }
    for(int i = 0; i < k/2; i++) {
        heapAdjust(&tmp[i], k);
    }
    

    for (int i = k; i < n; i++ ){
        if (arr[i] < tmp[0]) {
            tmp[0] = arr[i];
            heapAdjust(tmp, k);
        }

    }
}


int main()  {
    cout << "fuxx" << endl;
}