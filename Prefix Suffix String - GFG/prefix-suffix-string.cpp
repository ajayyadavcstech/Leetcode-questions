//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Node{
  public:
  vector<Node*> next;
  Node(){
      next.resize(26,NULL);
  }
};
 void addString(Node* root,string &str,int i){
      if(i==str.size()) return ;
      if(root->next[str[i]-'a']==NULL){
          Node* new_node = new Node();
          root->next[str[i]-'a'] = new_node;
      }
      addString(root->next[str[i]-'a'],str,i+1);
  }
  bool checkforprefix(Node* root,string &str,int i){
      if(i==str.size()) return true;
      if(root->next[str[i]-'a']==NULL) return false;
      return checkforprefix(root->next[str[i]-'a'],str,i+1);
  }
class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        Node* prefix = new Node();
        Node* suffix = new Node();
        for(auto str:s1){
            addString(prefix,str,0);
            reverse(str.begin(),str.end());
            addString(suffix,str,0);
        }
        int ans = 0;
        for(auto &x:s2){
            string a = x;
            reverse(a.begin(),a.end());
            if(checkforprefix(prefix,x,0) || checkforprefix(suffix,a,0)){
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends