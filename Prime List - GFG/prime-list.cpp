//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    bool is_prime(int n){
        if(n==1) return false;
        if(n==2 || n==3) return true;
        if(n%2==0 || n%3==0) return false;
        for(int i=5;i*i<=n;i+=6){
            if((n%(i))==0 || (n%(i+2))==0) return false;
        }
        return true;
    }
    int nearest_prime(int val){
        if(val==1) return 2;
        int n = val;
        int l,r;
        while(!is_prime(n)) n--;
        l = n;
        n = val;
        while(!is_prime(n)) n++;
        r = n;
        n = val;
        return (r-n<n-l) ? r : l;
    }
    Node *primeList(Node *head){
        Node* pt = head;
        while(pt){
            pt->val = nearest_prime(pt->val);
            pt = pt->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends