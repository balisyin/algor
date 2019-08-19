/* *
 * balisyin 20190819 成对交互单链表
 * */

#include<iostream>
#include"header.h"

using namespace std;

ListNode* pairwiseSwapLinkList1(ListNode* head) {
    ListNode *cur = head;
    while (cur != nullptr && cur->next != nullptr) {
        swap(cur->data, cur->next->data);
        cur = cur->next->next;
    }
    return head;
} //数据交换，简单，但是如果节点数据大，开销大


ListNode* pairwiseSwapLinkList2(ListNode* head) {
    if(head == nullptr || head->next ==  nullptr) return head;
    ListNode* remain = head->next->next;
    ListNode* newHead = head->next;
    newHead -> next = head;
    head->next = pairwiseSwapLinkList2(remain);

    return newHead;
} //指针交换，开销小

int main() {
    ListNode* pHead = new ListNode(0);
    ListNode* cur = pHead;
    for(auto i = 1; i < 10; i++) {
        ListNode* node = new ListNode(i);
        cur->next = node;
        cur = cur->next;
    }

    printLinkList(pHead);
    
    printLinkList(pairwiseSwapLinkList2(pHead));
    return 0;
}