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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy = ListNode(0,head);
        ListNode* temp = &dummy;

        while(true){
            ListNode* kth = temp;
            for(int i = 0; i < k; i++){
                kth = kth->next;
                if(kth == NULL){
                    return dummy.next;
                }
            }

            ListNode* nxt = kth->next;

            ListNode* prev = nxt;
            ListNode* cur = temp->next;
            while(cur != nxt){
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }

            ListNode* oldFirst = temp->next;
            temp->next = kth;
            temp = oldFirst;
        }

        return dummy.next;
    }
};
