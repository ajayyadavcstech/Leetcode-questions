class Solution {
public:
    bool solve(vector<vector<char>>&b,int i,int j,int n,int m){
        bool x = (!(i-1>=0) || b[i-1][j]!='X') ? true :  false;
        bool y = (!(j-1>=0) || b[i][j-1]!='X') ? true :  false;
        return x&&y;
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X' && solve(board,i,j,n,m)) ans++;
            }
        }
        return ans;
    }
};