//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	void solve(vector<vector<int>>&mat,int i,int j,vector<int> &v){
	    while(i<mat.size() && j>=0){
	        v.push_back(mat[i][j]);
	        i++;
	        j--;
	    }
	}
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int> ans;
		for(int i=0;i<A[0].size();i++){
		    solve(A,0,i,ans);
		}
		for(int i=1;i<A.size();i++){
		    solve(A,i,A[0].size()-1,ans);
		}
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends