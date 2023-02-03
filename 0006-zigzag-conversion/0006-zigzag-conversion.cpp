class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        unordered_map<int,string> mp;
        string ans;
        int i = 0;
        while(i<s.size()){
            for(int j=0;j<numRows && i<s.size();j++,i++){
                mp[j].push_back(s[i]);
            }
            for(int j=numRows-2;j>0 && i<s.size();j--,i++){
                mp[j].push_back(s[i]);
            }
        }
        for(int i=0;i<numRows;i++) ans+=mp[i];
        return ans;
    }
};