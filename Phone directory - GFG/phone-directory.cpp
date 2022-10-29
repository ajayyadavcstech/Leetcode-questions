//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class node{
  public:
  unordered_map<char,node*> mp;
  vector<int> pre;
};
class Solution{
public:
  void insert(node* root,string&s,int ind,int i){
      if(ind==s.size()) return ;
      if(root->mp.count(s[ind])==0) root->mp[s[ind]] = new node();
      root->mp[s[ind]]->pre.push_back(i);
      insert(root->mp[s[ind]],s,ind+1,i);
  }
  void solve(node* root,string&s,int ind,vector<vector<string>> &ans,string contact[]){
      if(ind==s.size() || root->mp.count(s[ind])==0) return ;
      node* temp = root->mp[s[ind]];
      vector<string> v;
      for(auto &x:temp->pre) v.push_back(contact[x]);
      ans.push_back(v);
      solve(temp,s,ind+1,ans,contact);
  }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        sort(contact,contact+n);
        set<string> st;
        node* root = new node();
        for(int i=0;i<n;i++){
            if(st.count(contact[i])==0)insert(root,contact[i],0,i);
            st.insert(contact[i]);
        }
        
        vector<vector<string>> ans;
        solve(root,s,0,ans,contact);
        while(ans.size()<s.size()) ans.push_back({"0"});
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends