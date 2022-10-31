//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool check(){
      
  }
    vector<int> satisfyEqn(int A[], int N) {
        // code here
        unordered_map<int,pair<int,int>> mp;
        vector<vector<int>> ans;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                int sum = A[i]+A[j];
                if(mp.count(sum)){
                    pair<int,int> x = mp[sum];
                    if(i!=x.first && i!=x.second && j!=x.first && j!=x.second) {
                        ans.push_back({x.first,x.second,i,j});
                    }
                }
                else  mp[sum]={i,j};
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size()) return ans[0];
        return {-1,-1,-1,-1};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends