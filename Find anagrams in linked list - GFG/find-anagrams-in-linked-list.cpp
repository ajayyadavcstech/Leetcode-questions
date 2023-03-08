//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        vector<Node*> ans;
        Node* pt1 = head;
        Node* pt2 = head;
        vector<int> dp1(26,0);
        vector<int> dp2(26,0);
        for(int i=0;i<s.size();i++) dp1[s[i]-'a']++;
        int cnt = 0;
        while(pt2){
            int ch = pt2->data - 'a';
            dp2[ch]++;
            cnt++;
            while(dp2[ch]>dp1[ch]){
                int ch = pt1->data-'a';
                dp2[ch]--;
                cnt--;
                pt1 = pt1->next;
            }
            if(cnt==s.size()){
                Node* next = pt2->next;
                ans.push_back(pt1);
                pt2->next = NULL;
                pt1 = next;
                pt2 = next;
                cnt = 0;
                for(int i=0;i<26;i++) dp2[i] = 0;
            }
            else pt2 = pt2->next;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends