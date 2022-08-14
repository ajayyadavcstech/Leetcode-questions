class Solution {
public:
    bool Valid(string &s1,string &s2){
        int cnt = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) cnt++;
            if(cnt>1) return false;
        }
        return cnt==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> adj;
        for(int i=0;i<wordList.size();i++){
            if(Valid(beginWord,wordList[i])){
                adj[beginWord].push_back(wordList[i]);
                adj[wordList[i]].push_back(beginWord);
            }
        }
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                if(Valid(wordList[i],wordList[j])){
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        if(adj.find(endWord)==adj.end() || adj[endWord].size()==0) return 0;  
        unordered_set<string> visited;
        queue<string> q;
        int level = 0;
        q.push(beginWord);
        visited.insert(beginWord);
        while(q.size()){
            int n = q.size();
            level++;
            while(n--){
                string st = q.front();
                q.pop();
                for(auto x : adj[st]){
                    if(x==endWord) return ++level;
                    if(visited.find(x)==visited.end()) {
                        q.push(x);
                        visited.insert(x);
                    }
                }
            }
        }
        return 0;
    }
};