class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n,int k,vector<int>& v){
        if(k==0) {
            ans.push_back(v);
            return ;
        }
        if(n==0) return ;
        solve(n-1,k,v);
        v.push_back(n);
        solve(n-1,k-1,v);
        v.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        solve(n,k,v);
        return ans;
    }
};