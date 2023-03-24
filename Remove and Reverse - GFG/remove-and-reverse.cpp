//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string str) {
        // code here
        vector<int> count(26,0);
        for(auto &x:str) count[x-'a']++;
        int n = str.size();
        int s = 0;
        int e = n-1;
        bool rev = false;
        while(s<n || e>=0){
            while(s<n){
                if(str[s]=='@'){
                    s++;
                    continue;
                } 
                if(count[str[s]-'a']>1){
                    count[str[s]-'a']--;
                    str[s] = '@';
                    s++;
                    rev = !rev;
                    break;
                }
                s++;
            }
            while(e>=0){
                if(str[e]=='@'){
                    e--;;
                    continue;
                }     
                if(count[str[e]-'a']>1){
                    count[str[e]-'a']--;
                    str[e]='@';
                    e--;
                    rev = !rev;
                    break;
                }
                e--;
            }
        }
        string ans;
        for(auto &x:str) if(x!='@') ans.push_back(x);
        if(rev) reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends