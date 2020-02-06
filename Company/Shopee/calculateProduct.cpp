#include<bits/stdc++.h>
using namespace std;

void calculateProduct(int* numbers, int num, int* products) {

    for(int i = 0; i < num; i++){
        products[i] = 1;
        for(int j = 0; j < num; j++) {
           
            if (i == j) {
                continue;
            }
            products[i] *= numbers[j]; 
            cout << "**:" << numbers[i] << " " << products[i] << endl;
        }
        cout << "pro:" << i << " " << products[i] << endl;
    }
    return;
}

int main(){
    int numbers[4] = {1,2,3,4};
    int num = sizeof(numbers)/sizeof(int);
    for(int i = 0; i < num; i++) {
        cout << numbers[i] << " " << endl;
    }
    int products[4];
    calculateProduct(numbers, num, products);
    for(int i = 0; i < num; i++) {
        cout << products[i] << " " << endl;
    }
    return 0;
}
