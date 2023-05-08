//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            //code here
            int sum = 0;
            int cnt = 1;
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]=='1'){
                    sum+=cnt;
                    sum%=m;
                }
                cnt*=2;
                cnt%=m;
            }
            return sum%m;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends