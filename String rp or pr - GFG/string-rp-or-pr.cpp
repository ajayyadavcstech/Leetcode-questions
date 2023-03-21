//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      //code here
      long long ans = 0;
      string str;
      int p1,p2;
      if(X>Y){
          str = "pr";
          p1 = X;
          p2 = Y;
      }
      else{
          str = "rp";
          p1 = Y;
          p2 = X;
      }
      stack<char> st;
      for(int i=0;i<S.size();i++){
          if(st.size() && st.top()==str[0] && S[i]==str[1]){
              st.pop();
              ans+=p1;
          }
          else{
              st.push(S[i]);
          }
      }
      S = "";
      while(st.size()){
          S.push_back(st.top());st.pop();
      }
      reverse(S.begin(),S.end());
      swap(str[0],str[1]);
      for(int i=0;i<S.size();i++){
          if(st.size() && st.top()==str[0] && S[i]==str[1]){
              st.pop();
              ans+=p2;
          }
          else{
              st.push(S[i]);
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends