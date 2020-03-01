/*20200226 balis
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in 
reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
#include<vector>
#include<map>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
        int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode *cur = head;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr) {
            int x = (l1==nullptr) ? 0 : l1->val;
            int y = (l2==nullptr) ? 0 : l2->val;
            int sum = x + y + carry;
            carry = sum%10;
            ListNode *next = new ListNode(sum/10);
            cur->next = next;
            cur = cur->next;
        }
        if (carry > 0) {
            ListNode *next = new ListNode(carry);
            cur->next = next;
        }
        return head->next;
    }
};