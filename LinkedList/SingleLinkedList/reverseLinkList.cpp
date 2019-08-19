/* *
 * balisyin 20190819 单链表反转
 * */
#include<iostream>
#include"header.h"

using namespace std;

ListNode* reverseLinkList(ListNode* head) {
    if(head == nullptr) return head;
    ListNode* pHead = head;
    ListNode   *pPre = pHead, *pCur = pHead->next, *pNext;
   
    while(pCur != nullptr) {
        pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
    }
    pHead-> next = nullptr;

    return pPre;

}

int main() {
    ListNode* pHead = new ListNode(0);
    ListNode* cur = pHead;
    for(auto i = 1; i < 10; i++) {
        ListNode* node = new ListNode(i);
        cur->next = node;
        cur = cur->next;
    }

    printLinkList(pHead);
    pHead = reverseLinkList(pHead);
    printLinkList(pHead);
    return 0;
}