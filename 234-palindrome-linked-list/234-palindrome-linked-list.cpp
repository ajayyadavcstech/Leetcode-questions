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
    bool isPalindrome(ListNode* &head,ListNode* mid){
        if(mid==NULL) return true;
        bool next = isPalindrome(head,mid->next);
        bool cur = head->val==mid->val;
        head = head->next;
        return next && cur;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;        
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return isPalindrome(head,slow);
    }
};