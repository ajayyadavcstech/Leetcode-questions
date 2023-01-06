//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
  vector<int> pre_com(){
      vector<int> p(10000,1);
      for(int i=2;i*i<10000;i++){
          for(int j = i*2;j<10000;j+=i){
              p[j] = 0;
          }
      }
      return p;
  }
  void solve(int n,unordered_set<int>&vis,vector<int>&p,queue<int>&q){
      if(p[n]==0) return ;
      if(vis.count(n)) return ;
      vis.insert(n);
      q.push(n);
  }
    int shortestPath(int Num1,int Num2)
    {   
        vector<int> p = pre_com();
        unordered_set<int> vis;
        vis.insert(Num1);
        queue<int> q;
        q.push(Num1);
        int ans = 0;
        while(q.size()){
            int n = q.size();
            while(n--){
                int cur = q.front();
                q.pop();
                if(cur==Num2) return ans;
                string str = to_string(cur);
                for(char i='0';i<='9';i++){
                    string s1 = str;
                    s1[3] = i;
                    string s2 = str;
                    s2[2] = i;
                    string s3 = str;
                    s3[1] = i;
                    string s4 = str;
                    s4[0] = i;
                    solve(stoi(s1),vis,p,q);
                    solve(stoi(s2),vis,p,q);
                    solve(stoi(s3),vis,p,q);
                    if(i!='0') solve(stoi(s4),vis,p,q);
                }
            }ans++;
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends