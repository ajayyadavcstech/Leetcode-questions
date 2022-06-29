class Solution {
public:
    static bool comp(vector<int>&v1,vector<int>&v2){
        if(v1[0]>v2[0]) return true;
        else if(v1[0]==v2[0] && v1[1]<v2[1]) return true;
        return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp);
        vector<vector<int>> ans;
        for(int i=0;i<people.size();i++){
            int h = people[i][0];
            int k = people[i][1];
            if(k+1>ans.size()){
                ans.push_back({h,k});
            }
            else{
                ans.insert(ans.begin()+k,{h,k});
            }
        }
        return ans;
    }
};