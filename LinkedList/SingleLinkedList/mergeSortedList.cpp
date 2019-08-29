/* *
 * balisyin 20190819 有序单链表合并
 * */

#include<iostream>
#include"header.h"

using namespace std;


ListNode* mergeSortedList(ListNode* pHead1, ListNode* pHead2){
    if(pHead1 == nullptr) return pHead2;
    if(pHead2 == nullptr) return pHead1;
    ListNode* pCur1 = pHead1;
    ListNode* pCur2 = pHead2;
    ListNode* pHead;
    if(pCur1-> data <= pCur2->data) {
        pHead = pCur1;
        pCur1 = pCur1->next;
    } else {
        pHead = pHead2;
        pCur2 = pCur2->next;
    }
    ListNode* pCur = pHead;

    while (pCur1 != nullptr && pCur2 != nullptr) {
        if(pCur1->data <= pCur2->data) {
            pCur->next = pCur1;
            pCur1 = pCur1->next;
        } else {
            pCur->next = pCur2;
            pCur2 = pCur2->next;
        }
        pCur = pCur->next;
    }
    

    
}

int main() {
    ListNode* pHead1 = new ListNode(0);
    ListNode* cur = pHead1;
    for(auto i = 2; i < 10; i = i+2) {
        ListNode* node = new ListNode(i);
        cur->next = node;
        cur = cur->next;
    }

    ListNode* pHead2 = new ListNode(1);
    cur = pHead2;
    for(auto i = 3; i < 10; i= i+2) {
        ListNode* node = new ListNode(i);
        cur->next = node;
        cur = cur->next;
    }



    printLinkList(pHead1);
    printLinkList(pHead2);

    //ListNode* pHead = mergeSortedList(pHead1, pHead2);
    
    //printLinkList(pHead);
    return 0;
}