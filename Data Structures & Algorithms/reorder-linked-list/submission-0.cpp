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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        ListNode* prev = slow->next = NULL;

        ListNode* nxt = second->next;
        ListNode* cur = second;
        while(cur){
            cur->next = prev;
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        ListNode* first = head;
        second = prev;
        slow = head;
        while(first && second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }        

    }
};
