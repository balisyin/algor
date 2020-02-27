#include<stdlib.h>
#include<stdio.h>
#include<sys/msg.h>
int main(){
    key_t key;
    if(key = ftok("alis", 'z') < 0) {
        perror("ftok err");
        exit(1);
    }
}