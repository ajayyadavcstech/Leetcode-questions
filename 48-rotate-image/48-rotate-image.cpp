class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;i+j<matrix.size();j++){
                swap(matrix[i][j],matrix[matrix.size()-1-j][matrix.size()-1-i]);
            } 
        }
    }
};