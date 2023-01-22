//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  int solve(vector<long long>&num,int x){
      int cnt = 0;
      for(int i=0;i<num.size();i++) if(x<=num[i] && num[i]%x==0) cnt++;
      return cnt;
  }
  vector<int> alldivisor(long long num){
      vector<int> v;
      for(int i=1;i<=sqrt(num);i++){
          if(num%i==0){
              v.push_back(i);
              v.push_back(num/i);
          }
      }
      return v;
  }
    int solve(int N, int K, vector<int> &arr) {
        // code here
        long long sum = 0;
        vector<long long> prefix(N);
        prefix[0] = arr[0];
        for(int i=1;i<N;i++){
            prefix[i] = prefix[i-1]+arr[i];
        }
        vector<int> div = alldivisor(prefix[N-1]);
        int ans = 1;
        for(auto &x:div){
            int cnt = solve(prefix,x);
            if(cnt>=K) ans = max(ans,x);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends