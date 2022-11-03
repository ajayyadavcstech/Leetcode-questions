class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int mx_ans = 0;
        int same_char = 0;
        for(auto &x:words){
            swap(x[0],x[1]);
            if(mp[x]){
                mp[x]--;
                mx_ans+=4;
                if(x[0]==x[1]) same_char--;
            }
            else{
                swap(x[0],x[1]);
                mp[x]++;
                if(x[0]==x[1]) same_char++;
            }
        }
        return mx_ans + (same_char ? 2 : 0);
    }
};