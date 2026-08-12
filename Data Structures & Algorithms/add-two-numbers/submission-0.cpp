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
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while(temp1 || temp2 || carry != 0){
            int v1 = temp1 ? temp1->val : 0;
            int v2 = temp2 ? temp2->val : 0;

            // int sum = temp1->val + temp2->val + carry;
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            cur->next = new ListNode(sum);
            cur = cur->next;
            temp1 = temp1 ? temp1->next : NULL;
            temp2 = temp2 ? temp2->next : NULL;
        }

        ListNode* ans = dummy->next;

        return ans;
        
    }
};
