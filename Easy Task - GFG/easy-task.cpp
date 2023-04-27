//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
public:
    void build(int node,string &s,int l,int r,vector<vector<int>>&arr){
        if(l==r){
            arr[node][s[l]-'a']++;
            return ;
        }
        
        int mid = (l+r)/2;
        build(2*node,s,l,mid,arr);
        build(2*node+1,s,mid+1,r,arr);
        for(int i=0;i<26;i++) arr[node][i] = arr[node*2][i]+arr[node*2+1][i];
    }
    void update(int node,string &s,int l,int r,int ind,char ch,vector<vector<int>>&arr,char pre){
        if(ind<l || ind>r) return ;
        if(l==r){
            arr[node][pre-'a']--;
            arr[node][ch-'a']++;
            s[ind] = ch;
            return ;
        }
        int mid = (l+r)/2;
        update(2*node,s,l,mid,ind,ch,arr,pre);
        update(2*node+1,s,mid+1,r,ind,ch,arr,pre);
        for(int i=0;i<26;i++) arr[node][i] = arr[node*2][i]+arr[node*2+1][i];
    }
    vector<int> get(int node,string &s,int ql,int qr,int l,int r,vector<vector<int>>&arr){
        if(qr<l || ql>r) return vector<int>(26,0);
        if(l>=ql && r<=qr) return arr[node];
        int mid = (l+r)/2;
        vector<int> arr1 = get(node*2,s,ql,qr,l,mid,arr);
        vector<int> arr2 = get(node*2+1,s,ql,qr,mid+1,r,arr);
        for(int i=0;i<26;i++) arr1[i]+=arr2[i];
        return arr1;
    }
    vector<char> easyTask(int n,string s,int qsize,vector<vector<string>> &q){
        // Code here
        vector<vector<int>> arr(4*n,vector<int>(26,0));
        build(1,s,0,s.size()-1,arr);
        vector<char> ans;
        for(int i=0;i<qsize;i++){
            int t = stoi(q[i][0]);
            if(t==1) update(1,s,0,s.size()-1,stoi(q[i][1]),q[i][2][0],arr,s[stoi(q[i][1])]);
            else{
                vector<int> brr = get(1,s,stoi(q[i][1]),stoi(q[i][2]),0,s.size()-1,arr);
                int k = stoi(q[i][3]);
                int cnt = 0;
                for(int i=25;i>=0;i--){
                    cnt+=brr[i];
                    if(cnt>=k) {
                        ans.push_back(i+'a');
                        break;
                    }
                }
            }
        }
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
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends