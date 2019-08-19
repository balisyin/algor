#include<iostream>
//using namespace std;
struct ListNode
{
   int data;
   ListNode* next;
   ListNode(int i) : data(i), next(nullptr) {};
};


void printLinkList(ListNode* pHead) {
    ListNode* cur = pHead;
    while(cur){
        std::cout << cur->data;
        cur = cur->next;
    }
    std::cout << std::endl;
}