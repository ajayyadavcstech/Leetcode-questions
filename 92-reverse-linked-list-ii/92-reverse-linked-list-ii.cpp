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
    ListNode* Reverse(ListNode* start,ListNode* end,ListNode* pre){
        if(start == end){
            start->next = pre;
            return start;
        }
        ListNode* head = Reverse(start->next,end,start);
        start->next = pre;
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* start = head;
        ListNode* end = head;
        int cnt;
        if(left!=1){
            cnt = 1;
            while(cnt<left-1){
                start = start->next;
                cnt++;
            }
        }
        cnt = 1;
        while(cnt<right) {
            end=end->next;
            cnt++;
        }
       if(left==1) return Reverse(head,end,end->next);
        start->next = Reverse(start->next,end,end->next);
        return head;
    }
};