class Solution {
public:
    set<vector<int>> dp;
    int solve(vector<vector<int>>& img1, vector<vector<int>>& img2,int i,int j,int m,int n){
        int row_diff = min(i,m);
        int col_diff = min(j,n);
        i-=row_diff;
        m-=row_diff;
        j-=col_diff;
        n-=col_diff;
        vector<int> v = {i,j,m,n};
        if(dp.count(v)) return 0;
        dp.insert(v);
        int s = img1.size();
        int ans = 0;
        for(;i<s && m<s ;i++,m++){
            for(int col1=j,col2=n;col1<s && col2<s;col1++,col2++){
                if(img1[i][col1] && img2[m][col2]) ans++;
            }
        }
        return ans;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> v1,v2;
        int n = img1.size();
        int ans = 0;
        for(int i=0;i<img1.size();i++){
            for(int j=0;j<img1[0].size();j++){
                if(img1[i][j]) v1.push_back({i,j});
                if(img2[i][j]) v2.push_back({i,j});
            }
        }

        for(auto &[i,j]:v1){
            for(auto &[m,n]:v2){
                ans = max(ans,solve(img1,img2,i,j,m,n));
            }
        }
        return ans;
    }
};