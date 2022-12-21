//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution{
    
public:
    Node* sortList(Node* head)
    {
        // Your Code Here
        Node* pos_s = NULL;
        Node* pos_e = NULL;
        Node* neg_s = NULL;
        Node* neg_e = NULL;
        while(head){
            Node* temp = head->next;
            if(head->data>=0){
                if(pos_s==NULL){
                    pos_s = head;
                    pos_e = head;
                    pos_e->next = NULL;
                }
                else{
                    pos_e->next = head;
                    pos_e = head;
                    pos_e->next = NULL;
                }
            }
            else {
                if(neg_s==NULL){
                    neg_s = head;
                    neg_e = head;
                    neg_e->next = NULL;
                }
                else{
                    head->next = neg_s;
                    neg_s = head;
                }
            }
            head = temp;
        }
        
        if(pos_s==NULL) return neg_s;
        else if(neg_s==NULL) return pos_s;
        neg_e->next = pos_s;
        return neg_s;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends