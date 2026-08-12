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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode dummy(0,head);
        ListNode* prev = &dummy;
        for(int i = 1; i < left ; i++){
            prev = prev->next;
        }
        ListNode* start = prev->next;

        ListNode* p = NULL;
        ListNode* cur = start;
        ListNode* nxt = cur->next;
        for(int i = 0; i <= right - left ; i++){
            cur->next = p;
            p = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        prev->next = p;
        start->next = cur;
        return dummy.next;
    }
};