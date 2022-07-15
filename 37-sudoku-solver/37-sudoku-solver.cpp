class Solution {
public:
    vector<vector<bool>> isContain;
    vector<vector<bool>> row ;
    vector<vector<bool>> col;
    bool solve(vector<vector<char>>&board,int part=1,int val=1){
        
        if(part==10 && val==10) return true;
        
        if(part==10){
            return solve(board,1,val+1);
        }
        
        if(isContain[part][val]) return solve(board,part+1,val);
        
        // part 1
        if(part==1){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(board[i][j]=='.' && row[i][val]==false && col[j][val]==false){
                        board[i][j]=val+'0';
                        isContain[part][val] = true;
                        row[i][val] = true;
                        col[j][val] = true;
                       if(solve(board,part+1,val)) return true;
                        board[i][j]='.';
                        isContain[part][val] = false;
                        row[i][val] = false;
                        col[j][val] = false;
                    }
                }
            }
        }
        // part 2
        else if(part==2){
            for(int i=0;i<3;i++){
                for(int j=3;j<6;j++){
                    if(board[i][j]=='.' && row[i][val]==false && col[j][val]==false){
                        board[i][j]=val+'0';
                        isContain[part][val] = true;
                        row[i][val] = true;
                        col[j][val] = true;
                       if(solve(board,part+1,val)) return true;
                        board[i][j]='.';
                        isContain[part][val] = false;
                        row[i][val] = false;
                        col[j][val] = false;
                    }
                }
            }
        }
        // part 3
        else if(part==3){
            for(int i=0;i<3;i++){
                for(int j=6;j<9;j++){
                    if(board[i][j]=='.' && row[i][val]==false && col[j][val]==false){
                        board[i][j]=val+'0';
                        isContain[part][val] = true;
                        row[i][val] = true;
                        col[j][val] = true;
                       if(solve(board,part+1,val)) return true;
                        board[i][j]='.';
                        isContain[part][val] = false;
                        row[i][val] = false;
                        col[j][val] = false;
                    }
                }
            }
        }
        
        
        // part 4
        else if(part==4){
            for(int i=3;i<6;i++){
                for(int j=0;j<3;j++){
                     if(board[i][j]=='.' && row[i][val]==false && col[j][val]==false){
                        board[i][j]=val+'0';
                        isContain[part][val] = true;
                        row[i][val] = true;
                        col[j][val] = true;
                       if(solve(board,part+1,val)) return true;
                        board[i][j]='.';
                        isContain[part][val] = false;
                        row[i][val] = false;
                        col[j][val] = false;
                    }
                }
            }
        }
        // part 5
        else if(part==5){
            for(int i=3;i<6;i++){
                for(int j=3;j<6;j++){
                   if(board[i][j]=='.' && row[i][val]==false && col[j][val]==false){
                        board[i][j]=val+'0';
                        isContain[part][val] = true;
                        row[i][val] = true;
                        col[j][val] = true;
                       if(solve(board,part+1,val)) return true;
                        board[i][j]='.';
                        isContain[part][val] = false;
                        row[i][val] = false;
                        col[j][val] = false;
                    }
                }
            }
        }
        // part 6
        else if(part==6){
            for(int i=3;i<6;i++){
                for(int j=6;j<9;j++){
                   if(board[i][j]=='.' && row[i][val]==false && col[j][val]==false){
                        board[i][j]=val+'0';
                        isContain[part][val] = true;
                        row[i][val] = true;
                        col[j][val] = true;
                       if(solve(board,part+1,val)) return true;
                        board[i][j]='.';
                        isContain[part][val] = false;
                        row[i][val] = false;
                        col[j][val] = false;
                    }
                }
            }
        }
        
        
        // part 7
        else if(part==7){
            for(int i=6;i<9;i++){
                for(int j=0;j<3;j++){
                   if(board[i][j]=='.' && row[i][val]==false && col[j][val]==false){
                        board[i][j]=val+'0';
                        isContain[part][val] = true;
                        row[i][val] = true;
                        col[j][val] = true;
                       if(solve(board,part+1,val)) return true;
                        board[i][j]='.';
                        isContain[part][val] = false;
                        row[i][val] = false;
                        col[j][val] = false;
                    }
                }
            }
        }
        // part 8
        else if(part==8){
            for(int i=6;i<9;i++){
                for(int j=3;j<6;j++){
                   if(board[i][j]=='.' && row[i][val]==false && col[j][val]==false){
                        board[i][j]=val+'0';
                        isContain[part][val] = true;
                        row[i][val] = true;
                        col[j][val] = true;
                       if(solve(board,part+1,val)) return true;
                        board[i][j]='.';
                        isContain[part][val] = false;
                        row[i][val] = false;
                        col[j][val] = false;
                    }
                }
            }
        }
        // part 9
        else if(part==9){
            for(int i=6;i<9;i++){
                for(int j=6;j<9;j++){
                    if(board[i][j]=='.' && row[i][val]==false && col[j][val]==false){
                        board[i][j]=val+'0';
                        isContain[part][val] = true;
                        row[i][val] = true;
                        col[j][val] = true;
                       if(solve(board,part+1,val)) return true;
                        board[i][j]='.';
                        isContain[part][val] = false;
                        row[i][val] = false;
                        col[j][val] = false;
                    }
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        isContain.resize(10,vector<bool>(10,false));
        row.resize(9,vector<bool>(10,false)); 
        col.resize(9,vector<bool>(10,false)); 
        int part = 1;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                part=1;
                if(i>=3) part = 4;
                if(i>=6) part = 7;
                if(j>=3) part++;
                if(j>=6) part++;
                
                if(board[i][j]!='.'){
                    row[i][board[i][j]-'0']= true;
                    col[j][board[i][j]-'0'] = true;
                    isContain[part][board[i][j]-'0'] = true;
                }
            }
        }
        solve(board);
    }
};