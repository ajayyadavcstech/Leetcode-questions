//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    //Complete the function and return minimum number of operations
    public:
    bool is_palindrome(string &str,int i,int j,int &cnt){
        int s = 0;
        int e = str.size()-1;
        while(s<e){
            if((s>=i && s<=j) && (e>=i && e<=j)){
                if(str[s]!=str[e]) return false;   
            }
            else if(str[s]!=str[e]) cnt++;
            s++;e--;
        }
        return true;
        
    }
    int specialPalindrome(string s1, string s2){
        //Code Here
        int mn = INT32_MAX;
        int n = s1.size();
        int m = s2.size();
        for(int i=0;i<=(n-m);i++){
            string temp = s1;
            int cnt1 = 0;
            for(int j=0;j<m;j++){
                if(temp[i+j]!=s2[j]){
                    temp[i+j] = s2[j];
                    cnt1++;
                }
            }
            int cnt2 = 0;
            if(is_palindrome(temp,i,i+m-1,cnt2)) mn = min(mn,cnt1+cnt2);
        }
        return mn==INT32_MAX ? -1 : mn;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends