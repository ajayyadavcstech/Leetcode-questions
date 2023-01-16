class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newInter) {
        int n = inter.size();
        if(n==0) return {newInter};
        vector<vector<int>> ans;
        int i = 0;
        while(i<n && inter[i][1]<newInter[0]){
            ans.push_back(inter[i]);
            i++;
        }
        
        vector<int> temp = newInter;
        if(i<n) temp[0] = min(temp[0],inter[i][0]);
        while(i<n && inter[i][0]<=newInter[1]) i++;
        if(i!=0) temp[1] = max(temp[1],inter[i-1][1]);
        ans.push_back(temp);
        
        while(i<n && inter[i][0]>newInter[1]){
            ans.push_back(inter[i]);
            i++;
        }
        
        return ans;
    }
};