class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> num(26,0);
        for(auto &x : sentence){
            num[x-'a']++;
        }
        for(auto &x : num) if(!x) return false;
        return true;
    }
};