class Solution {
public:
    unordered_map<char,int> mapping;
    bool correct_order(string &s1,string &s2){
        int i;
        for(i=0;i<s1.size() && i<s2.size();i++){
            if(mapping[s1[i]]==mapping[s2[i]]) continue;
            else if(mapping[s1[i]]<mapping[s2[i]]) return true;
            else return false;
        }
        return i==s1.size() ? true : false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.size();i++) mapping[order[i]] = i;
        for(int i=0;i<words.size()-1;i++){
            if(!correct_order(words[i],words[i+1])) return false;
        }
        return true;
    }
};