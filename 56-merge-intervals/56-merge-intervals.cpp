class Solution {
public:
    static bool comp(vector<int> &v1,vector<int>&v2){
        if(v1[0]<v2[0]){
            return true;
        }
        else if(v1[0]==v2[0] && v1[1]<v2[1]){
            return true;
        }
        else return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int> &pre = ans[ans.size()-1];
            vector<int>&cur = intervals[i];
            if(pre[0]==cur[0]){
                pre[1]=cur[1];
            }
            else if(pre[1]>=cur[0]){
                pre[1] = max(cur[1],pre[1]);
            }
            else{
                ans.push_back(cur);
            }
        }
        return ans;
    }
};