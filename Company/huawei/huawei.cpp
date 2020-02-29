#include<stdio.h>
#include<iostream>

using namespace std;
void getMemory(char *p) {
    //p = (char *)malloc(100);
    p = new char[100];
    return;
}
int main(int argc, char *arg[]) {

    char *p = nullptr;
    // getMemory(p);
    p = new char[100];
    strcpy(p, "balis");
    cout << p << endl;
    //free(p);
    delete p;
    return 0;

}