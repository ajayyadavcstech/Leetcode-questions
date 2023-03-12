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
class comp{
  public:
    bool operator()(ListNode* p1,ListNode* p2) {
        return p1->val > p2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp> pq;
        ListNode* head = new ListNode();
        ListNode* tail = head;
        for(auto &x:lists) if(x)pq.push(x);
        while(pq.size()){
            ListNode* node = pq.top();
            if(node->next!=NULL) pq.push(node->next);
            pq.pop();
            tail->next = node;
            tail = node;
            tail->next = NULL;
        }
        return head->next;
    }
};