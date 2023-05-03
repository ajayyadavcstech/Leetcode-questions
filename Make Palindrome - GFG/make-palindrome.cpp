//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool palindrome(string &str){
        int s=0;
        int e = str.size()-1;
        while(s<e){
            if(str[s]!=str[e]) return false;
            s++;e--;
        }
        return true;
    }
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        unordered_map<string,int> mp;
        for(int i=0;i<arr.size();i++){
            string str = arr[i];
            reverse(arr[i].begin(),arr[i].end());
            mp[str]++;
        }
        for(int i=0;i<n;i++){
            string str = arr[i];
            reverse(arr[i].begin(),arr[i].end());
            if(!palindrome(arr[i])){
                if(mp[str]==0) return false;
                mp[str]--;
            }
        }
        int cnt = 0;
        for(auto &x:mp){
            if(x.second&1) cnt++;
            if(cnt>1) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends