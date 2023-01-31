class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> num;
        int n = scores.size();
        for(int i=0;i<n;i++){
            num.push_back({ages[i],scores[i]});
        }
        sort(num.begin(),num.end());
        vector<int> ans(n,0);
        int mx_score = 0;
        for(int i=0;i<n;i++){
            ans[i] = num[i].second;
            for(int j=0;j<i;j++){
                if(num[j].second<=num[i].second){
                    ans[i] = max(ans[i],ans[j]+num[i].second);
                }
            }
            mx_score = max(mx_score,ans[i]);
        }
        return mx_score;
    }
};