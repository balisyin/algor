/*20200226 balis
Merge two sorted linked lists and return it as a new list. The new list 
should be made by splicing together the nodes of the first two lists.
Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
#include<vector>
#include<map>

using namespace std;

struct ListNode {
        int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* pHead1, ListNode* pHead2) {
         if(pHead1 == nullptr) return pHead2;
    if(pHead2 == nullptr) return pHead1;
    ListNode* pCur1 = pHead1;
    ListNode* pCur2 = pHead2;
    ListNode* pHead;
    if(pCur1-> val <= pCur2->val) {
        pHead = pCur1;
        pCur1 = pCur1->next;
    } else {
        pHead = pHead2;
        pCur2 = pCur2->next;
    }
    ListNode* pCur = pHead;

    while (pCur1 != nullptr && pCur2 != nullptr) {
        if(pCur1->val <= pCur2->val) {
            pCur->next = pCur1;
            pCur1 = pCur1->next;
        } else {
            pCur->next = pCur2;
            pCur2 = pCur2->next;
        }
        pCur = pCur->next;
    }
     if(pCur1 != nullptr) {
        pCur->next = pCur1;
    }
     if(pCur2 != nullptr) {
        pCur->next = pCur2;
    }
    return pHead;
    }
};