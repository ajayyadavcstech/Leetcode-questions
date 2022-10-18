class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int>&task,int ses_time,vector<int>&v,int ind){
        if(ind==task.size()) return true;
        for(int i=0;i<v.size();i++){
            if(v[i]+task[ind]<=ses_time){
                v[i]+=task[ind];
                if(solve(task,ses_time,v,ind+1)) return true;
                v[i]-=task[ind];
                if(v[i]==0) break;
            }
        }
        return false;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        int i = 1;
        int j = tasks.size();
        int ans = 0;
        while(i<=j){
            int mid = (i+j)/2;
            vector<int> v(mid,0);
            bool check = solve(tasks,sessionTime,v,0);
            if(check){
                ans = mid;
                j = mid-1;
            }
            else i = mid+1;
        }
        return ans;
    }
};