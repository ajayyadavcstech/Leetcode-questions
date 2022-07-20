class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }
        int cnt=0;
        for(auto x : words){
            int pre = -1;
            for(auto ch : x){
                if(mp.find(ch)==mp.end()) {
                    cnt--;
                    break;
                }
                vector<int> &ind = mp[ch];
                bool check = false;
                for(int i=0;i<ind.size();i++){
                    if(ind[i]>pre) {
                        pre = ind[i];
                        check = true;
                        break;
                    }
                }
                if(!check){
                   cnt--;
                    break;
                }
            }
            cnt++;
        }
        return cnt;
    }
};