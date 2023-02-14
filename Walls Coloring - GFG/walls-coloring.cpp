//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        int pink = 0;
        int black = 0;
        int yellow = 0;
        for(int i=0;i<N;i++){
            int new_pink = colors[i][0] + min(black,yellow);
            int new_black = colors[i][1] + min(pink,yellow);
            int new_yellow = colors[i][2] + min(pink,black);
            pink = new_pink;
            black = new_black;
            yellow = new_yellow;
        }
        return min(pink,min(black,yellow));
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends