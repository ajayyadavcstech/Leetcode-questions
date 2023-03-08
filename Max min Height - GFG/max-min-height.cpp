//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    bool solve(long long num,int k,int w,vector<int>&a){
        vector<long long> pre(a.size()+2,0);
        long long cnt = 0;
        for(int i=0;i<a.size();i++){
            cnt-=pre[i];
            long long curHeight = a[i]+cnt;
            if(curHeight<num){
                long long diff = num-curHeight;
                if(diff>k) return false;
                cnt+=diff;
                k-=diff;
                if(i+w<pre.size())pre[i+w] = diff;
            }
        }
        return true;
    }
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            long long s = 0;
            long long e = 10e10;
            long long ans = 0;
            while(s<=e){
                long long mid = s + (e-s)/2;
                if(solve(mid,k,w,a)){
                    ans = mid;
                    s = mid + 1;
                }else e = mid-1;
            }
            return ans;
        }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends