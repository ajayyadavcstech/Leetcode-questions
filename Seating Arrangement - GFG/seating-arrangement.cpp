//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int m, int n, vector<int>& seats){
        // Write your code here.
        if(m==0) return true;
        for(int i=0;i<n;i++){
            if(seats[i]==1) continue;
            int l = (i==0 ? 0 : seats[i-1]);
            int r = (i==n-1 ? 0 : seats[i+1]);
            if(l==0 && r==0){
                seats[i] = 1;
                m--;
            }
            if(m==0) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends