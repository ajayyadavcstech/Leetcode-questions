class Solution {
public:
    vector<bool> visited;
    int solve(string start,string end,vector<string>&bank){
        if(start==end) return 0;
        int ans = INT32_MAX;
        for(int i=0;i<bank.size();i++){
            if(visited[i]) continue;
            bool check = true;
            int cnt = 0;
            for(int j=0;j<start.size();j++){
                if(start[j]!=bank[i][j]) cnt++;
                if(cnt>1) {
                    check = false;
                    break;
                }
            }
            visited[i] = true;
            if(check){
                int val = solve(bank[i],end,bank);
                if(val!=-1) ans = min(ans,1+val);
            }
            visited[i] = false;
        }
        return (ans==INT32_MAX ? -1 : ans);
    }
    int minMutation(string start, string end, vector<string>& bank) {
        visited.resize(bank.size(),false);
        return solve(start,end,bank);
    }
};