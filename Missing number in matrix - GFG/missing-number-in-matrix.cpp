//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool row(vector<vector<long long> >& mat,long long sum=0){
        for(int i=0;i<mat.size();i++){
            long long cur = 0;
            for(int j=0;j<mat.size();j++){
                cur+=mat[i][j];
            }
            if(sum==0) sum=cur;
            else if(cur!=sum) return false;
        }
        return true;
    }
    bool col(vector<vector<long long> >& mat,long long sum=0){
        for(int i=0;i<mat.size();i++){
            long long cur = 0;
            for(int j=0;j<mat.size();j++){
                cur+=mat[j][i];
            }
            if(sum==0) sum = cur;
            else if(cur!=sum) return false;
        }
        return true;
    }
    bool dig(vector<vector<long long>>&mat,long long sum=0){
        long long cur = 0;
        for(int i=0;i<mat.size();i++){
            cur+=mat[i][i];
        }
        sum=cur;
        cur = 0;
        for(int i=0;i<mat.size();i++){
            cur+=mat[i][mat.size()-i-1];
        }
        
        if(cur!=sum) return false;
        return true;
    }
    long long int MissingNo(vector<vector<int> >& mat) {
        // Code here
        int r,c;
        long long sum = 0;
        long long mn = INT64_MAX;
        vector<vector<long long>> matrix(mat.size(),vector<long long>(mat.size()));
        for(int i=0;i<mat.size();i++){
            long long cur = 0;
            for(int j=0;j<mat.size();j++){
                cur=cur+(long)mat[i][j];
                matrix[i][j] = mat[i][j];
                if(mat[i][j]==0){
                    r= i;
                    c=j;
                }
            }
            sum = max(sum,cur);
            mn = min(mn,cur);
        }
        matrix[r][c] = sum-mn;
        if(matrix[r][c]<=0) return -1;
        return (row(matrix) && col(matrix) && dig(matrix)) ? matrix[r][c] : -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends