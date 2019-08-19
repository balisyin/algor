/* * balisyin 20190211 * */
//相加两个单链表表示的数字  例如 1->2->3 + 8->9->9 = 1->0->2->2


// https://www.geeksforgeeks.org/sum-of-two-linked-lists/


#include<iostream>
#include"header.h"

using namespace std;


ListNode* addList(ListNode* list1, ListNode* list2){
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;
    ListNode *cur1= list1, *cur2 = list2;
    int data = cur1->data + cur2->data;
    int carry = data / 10;
    data = data % 10;
    cur1 = cur1 ->next;
    cur2 = cur2 ->next;
    ListNode* nList = new ListNode(data);
    ListNode* pHead = nList;
    
    while(cur1 != nullptr && cur2 != nullptr) {
        data = cur1->data + cur2->data + carry;
        carry = data / 10;
        data = data % 10;
        ListNode * newNode = new ListNode(data);
        nList->next = newNode;
        nList = nList->next;
        cur1 = cur1->next;
        cur2 = cur2->next;
        //cout << "2:" << data << "  " << carry << endl;

    }
    if (cur1 == nullptr) cur1 = cur2;
    while(cur1 != nullptr) {
        data = cur1->data + carry;
        carry = data / 10;
        data = data % 10;
        ListNode * newNode = new ListNode(data);
        nList->next = newNode;
        nList = nList->next;
        cur1 = cur1->next;
        //cout << "1:" << data << "  " << carry << endl;

    }
    return pHead;
}


ListNode* reverseList(ListNode* pHead) {
    if(pHead == nullptr || pHead->next == nullptr) return pHead;
    ListNode* pPre = pHead;
    ListNode* pCur = pHead->next;
    ListNode* pNext;
    while(pCur != nullptr) {
        pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
    }
    
    pHead ->next = nullptr;
    return pPre;
}



int main() {
    ListNode* pHead1 = new ListNode(1);
    ListNode* cur = pHead1;
    for(auto i = 2; i < 4; i++) {
        ListNode* node = new ListNode(i);
        cur->next = node;
        cur = cur->next;
    }

    ListNode* pHead2 = new ListNode(6);
    cur = pHead2;
    for(auto i = 7; i < 10; i++) {
        ListNode* node = new ListNode(i);
        cur->next = node;
        cur = cur->next;
    }



    printLinkList(pHead1);
    printLinkList(pHead2);
    pHead1 = reverseList(pHead1);
    pHead2 = reverseList(pHead2);
    //printLinkList(pHead1);
    //printLinkList(pHead2);
    ListNode* pHead = addList(pHead1, pHead2);
    pHead = reverseList(pHead);
    printLinkList(pHead);
    return 0;
}