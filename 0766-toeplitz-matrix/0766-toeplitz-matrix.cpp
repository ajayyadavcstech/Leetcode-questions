class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<m;i++){
            int k = 0,l = i;
            int val = matrix[k][l];
            while(k<n && l<m){
                if(matrix[k][l]!=val) return false;
                k++,l++;
            }
        }
        for(int i=1;i<n;i++){
            int k = i,l = 0;
            int val = matrix[k][l];
            while(k<n && l<m){
                if(matrix[k][l]!=val) return false;
                k++,l++;
            }
        }
        return true;
    }
};