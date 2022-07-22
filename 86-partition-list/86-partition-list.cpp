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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy =new ListNode(-1);
        dummy->next = head;
        ListNode* start = dummy;
        while(start->next && start->next->val<x) start=start->next;
        if(!start->next) return dummy->next;
        ListNode* cur = start->next;
        while(cur->next){
            while(cur->next && !(cur->next->val<x)) cur = cur->next;
            if(!cur->next) break;
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            temp->next = start->next;
            start->next = temp;
            start = temp;
        }
        return dummy->next;
    }
};