class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> mp;
        for(int i=0;i<words.size();i++){
            string st;
            for(int j=0;j<words[i].size();j++){
                st = st + v[words[i][j]-'a'];
            }
            mp.insert(st);
        }
        return mp.size();
    }
};