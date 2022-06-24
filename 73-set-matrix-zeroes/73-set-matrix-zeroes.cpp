class Solution {
public:
    unordered_set<int> row;
    unordered_set<int> col;
    void MakeRow_Zero(vector<vector<int>>&mat,int row){
        for(int i=0;i<mat[0].size();i++){
            mat[row][i] = 0;
        }
    }
     void MakeCol_Zero(vector<vector<int>>&mat,int col){
        for(int i=0;i<mat.size();i++){
            mat[i][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0) v.push_back(make_pair(i,j));
            }
        }
        for(auto p : v){
            int row1 = p.first;
            int col1 = p.second;
            if(row.find(row1)==row.end()){
                MakeRow_Zero(matrix,row1);
                row.insert(row1);
            }
            if(col.find(col1)==col.end()){
                MakeCol_Zero(matrix,col1);
                col.insert(col1);
            }
        }
    }
};