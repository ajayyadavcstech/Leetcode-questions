//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long Xor = 0;
        for(int i=0;i<N;i++){
            Xor = Xor^Arr[i];
        }
        long long set_bit = Xor&(~(Xor-1));
        long long a = 0;
        for(int i=0;i<N;i++){
            if(Arr[i]&set_bit) a = a^Arr[i];
        }
        long long b = a^Xor;
        return {max(a,b),min(a,b)};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends