class Solution {
public:
    int count(string &st){
        int cnt = 0;
        for(int i=0;i<st.size();i++){
            if(st[i]==' ') cnt++;
        }
        return cnt+1;
    }
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(int i=0;i<sentences.size();i++){
            ans=max(ans,count(sentences[i]));
        }
        return ans;
    }
};