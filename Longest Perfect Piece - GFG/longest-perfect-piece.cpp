//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        // code here
        int ans = 0;
        map<int,int> mp;
        int i = 0;
        for(int j=0;j<N;j++){
            mp[arr[j]]++;
            auto mx = mp.rbegin();
            auto mn = mp.begin();
            while(mp.size() && (*mx).first-(*mn).first>1){
                mp[arr[i]]--;
                if(mp[arr[i]]==0) mp.erase(arr[i]);
                mx = mp.rbegin();
                mn = mp.begin();
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends