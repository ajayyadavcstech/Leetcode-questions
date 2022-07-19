class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& st, int time) {
        int cnt = 0;
        int i = 0;
        int j = time;
        vector<int> ans;
        while(j<st.size()){
            if(cnt==time){
                ans.push_back(i);
                cnt--;
            }
            if(j!=st.size()-1 && st[i]>=st[i+1] && st[j]<=st[j+1]) {
                i++;
                j++;
                cnt++;
            }
            else{
                i++;
                j++;
                cnt = 0;
            }
        }
        return ans;
    }
};