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
    int list_size(ListNode* root){
        if(!root) return 0;
        return 1 + list_size(root->next);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* root= head;
        n = list_size(head) - n;
        if(!n) return head->next;
        while(root){
            if(n==1){
                root->next = root->next->next;
                break;  
            }
            n--;
            root = root->next;
        }
        return head;
    }
};