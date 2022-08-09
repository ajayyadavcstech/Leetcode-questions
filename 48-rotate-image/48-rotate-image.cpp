class Solution {
public:
    void reverse(vector<int> &arr){
        int s = 0;
        int e = arr.size()-1;
        while(s<=e){
            swap(arr[s++],arr[e--]);
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i]);
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;i+j<matrix.size()-1;j++){
                swap(matrix[i][j],matrix[matrix.size()-1-j][matrix.size()-i-1]);
            }
        }
    }
};