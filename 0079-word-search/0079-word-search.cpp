class Solution {
public:
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    bool solve(vector<vector<char>>&b,string &w,int i,int j,int k=0){
        if(k==w.size()) return true;
        if(i<0 || j<0 || i==b.size() || j==b[0].size()) return false;
        if(w[k]!=b[i][j]) return false;
        b[i][j] = '.';
        for(int l=0;l<4;l++) {
            if(solve(b,w,i+row[l],j+col[l],k+1)){
                b[i][j]=w[k];
                return true;
            }  
        }
        b[i][j] = w[k];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(board,word,i,j)) return true;
            }
        }
        return false;
    }
};