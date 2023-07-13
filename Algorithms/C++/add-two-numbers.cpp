/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0) {
            carry += l1 != nullptr ? l1->val : 0;
            carry += l2 != nullptr ? l2->val : 0;
            current->next = new ListNode(carry % 10);
            current = current->next;
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
            carry = carry / 10;
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
