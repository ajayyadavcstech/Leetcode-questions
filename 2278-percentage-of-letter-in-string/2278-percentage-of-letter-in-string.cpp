class Solution {
public:
    int percentageLetter(string s, char letter) {
        float cnt = 0;
        for(auto &x:s) if(x==letter) cnt++;
        return (cnt*100/s.size());
    }
};