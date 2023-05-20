//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N%groupSize!=0) return false;
        map<int,int> mp;
        for(int i=0;i<N;i++) mp[hand[i]]++;
        while(mp.size()){
            if(mp.size()<groupSize) return false;
            map<int,int> ::iterator it = mp.begin();
            for(int i=1;i<groupSize;i++){
                int a = it->first;
                it++;
                int b = it->first;
                if(a!=b-1) return false;
                mp[a]--;
                if(mp[a]==0) mp.erase(a);
            }
            mp[it->first]--;
            if(it->second==0) mp.erase(it);
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends