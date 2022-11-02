class Solution {
public:
    int diff_char(string&s1,string&s2){
        int cnt = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) cnt++;
        }
        return cnt;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        vector<bool> visited(bank.size(),false);
        q.push(start);
        int step = 0;
        while(q.size()){
            int n = q.size();
            
            while(n--){
                string cur = q.front();
                if(cur==end) return step;
                q.pop();
                for(int i=0;i<bank.size();i++){
                    if(visited[i]) continue;
                    int cnt = diff_char(bank[i],cur);
                    if(cnt<2){
                        visited[i] = true;
                        q.push(bank[i]);
                    }
                }
            }step++;
        }
        return -1;
    }
};