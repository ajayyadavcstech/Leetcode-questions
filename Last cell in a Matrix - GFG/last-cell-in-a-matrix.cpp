//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int n, int m){
        //code here
        char dir = 'r';
        int R = 0;
        int C = 0;
        while(true){
            int newR = R;
            int newC = C;
            if(matrix[R][C]==0){
               if(dir=='r') newC +=1;
               else if(dir=='l') newC-=1;
               else if(dir=='d') newR +=1;
               else newR -=1;
            }
            else{
                matrix[R][C] = 0;
               if(dir=='r') dir = 'd';
               else if(dir=='l') dir = 'u';
               else if(dir=='d') dir = 'l';
               else dir = 'r';
            }
            if(!(newR>=0 && newC>=0 && newR<n && newC<m)) break;
            R = newR;
            C = newC;
        }
        return make_pair(R,C);
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends