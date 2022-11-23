class Solution {
public:
    bool solve(vector<int>&ind,vector<vector<char>>&b){
        int i = ind[0],j=ind[1];
        unordered_set<char> box;
        int cnt = 0;
        for(int l=0;l<3;l++){
            for(int m=0;m<3;m++){
                if(b[l+i][j+m]=='.') continue;
                cnt++;
                box.insert(b[l+i][j+m]);
            }
        }
        return cnt==box.size();
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> box = {{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
        for(int i=0;i<board.size();i++){
            unordered_set<char> row,col;
            for(int j=0;j<board.size();j++){
                if(board[i][j]!='.'){
                    int r = row.size();
                    row.insert(board[i][j]);
                    if(r==row.size()) return false;
                }
                if(board[j][i]!='.'){
                    int c=col.size();
                    col.insert(board[j][i]);
                    if(c==col.size()) return false;
                }
            }
        }
        for(int i=0;i<9;i++){
            if(!solve(box[i],board)) return false;
        }
        return true;
    }
};