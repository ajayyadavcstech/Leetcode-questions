/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* cur = node;
        ListNode* next = node->next;
        ListNode* pre = NULL;
        while(next){
            swap(cur->val,next->val);
            pre = cur;
            cur = next;
            next = next->next;
        }
        pre->next = NULL;
    }
};