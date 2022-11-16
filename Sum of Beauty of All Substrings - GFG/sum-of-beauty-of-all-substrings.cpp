//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int beauty_string(vector<int>&fre){
      int mx = INT32_MIN;
      int mn = INT32_MAX;
      for(auto &x:fre){
          if(x==0) continue;
          mx = max(mx,x);
          mn = min(mn,x);
      }
      return mx-mn;
  }
    int beautySum(string s) {
        // Your code goes here
        int count = 0;
        for(int i=0;i<s.size();i++){
            vector<int> fre(26,0);
            for(int j=i;j<s.size();j++){
                fre[s[j]-'a']++;
                count+=(beauty_string(fre));
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends