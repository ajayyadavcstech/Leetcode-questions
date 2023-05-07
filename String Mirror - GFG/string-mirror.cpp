//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        if(str.size()>1 && str[0]==str[1]){
            string cur;
            cur.push_back(str[0]);
            cur.push_back(str[0]);
            return cur;
        }
        string ans;
        ans.push_back(str[0]);
        for(int i=1;i<str.size();i++){
            if(str[i]<=str[i-1]) ans.push_back(str[i]);
            else break;
        }
        string res = ans;
        reverse(ans.begin(),ans.end());
        res+=ans;
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends