class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<int,unordered_map<char,int>> mpword1;
        unordered_map<char,int> mpword2;
        vector<string> ans;
        
        for(int i=0;i<words1.size();i++){
            for(auto x : words1[i]){
                mpword1[i][x]++;
            }
        }
        for(int i=0;i<words2.size();i++){
            unordered_map<char,int> temp;
            for(auto x : words2[i]){
                temp[x]++;
                mpword2[x] = max(mpword2[x],temp[x]);
            }
        }
        for(int i=0;i<words1.size();i++){
            bool check = true;
            for(auto x : mpword2){
                if(x.second > mpword1[i][x.first]){
                    check = false;
                    break;
                }
            }
            if(check) ans.push_back(words1[i]);
        }
        return ans;
    }
};