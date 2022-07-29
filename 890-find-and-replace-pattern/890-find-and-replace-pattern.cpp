class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto st:words){
            unordered_map<char,char> mpword;
            unordered_map<char,char> mppat;
            int i = 0;
            for( i=0;i<st.size();i++){
                if(mpword.find(st[i])==mpword.end() && mppat.find(pattern[i])==mppat.end()){
                    mpword[st[i]] = pattern[i];
                    mppat[pattern[i]] = st[i];
                }
                else if(mpword.find(st[i])==mpword.end() && mppat.find(pattern[i])!=mppat.end()){
                    break;
                }
                else if(mpword.find(st[i])!=mpword.end() && mpword[st[i]]!=pattern[i]) break;
            }
            if(i==pattern.size()) ans.push_back(st);
        }
        return ans;
    }
};