class Solution {
public:
    int Kadens(vector<vector<int>>&matrix,int cur,int pre,int k){
        set<int> st;
        st.insert(0);
        int sum = 0;
        int mx = -1000000;
        for(int i=0;i<matrix[0].size();i++){
            sum+=matrix[cur][i] - matrix[pre][i];
            auto it = st.lower_bound(sum-k);
            if(it!=st.end()) mx = max(mx,sum-*it);
            st.insert(sum);
        }
        return mx;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
         vector<vector<int>> mat;
         int ans = -100000;
         mat.push_back(vector<int>(matrix[0].size(),0));
         for(int i=0;i<matrix.size();i++){
             vector<int> v;
             for(int j=0;j<matrix[0].size();j++){
                 v.push_back(matrix[i][j]+mat[i][j]);
             }
             mat.push_back(v);
         }
         for(int i=1;i<mat.size();i++){
             for(int j=0;j<i;j++){
                 int val = Kadens(mat,i,j,k);
                 ans = max(ans,val);
                 if(ans==k) return ans;
             }
         }
        return ans;
    }
};