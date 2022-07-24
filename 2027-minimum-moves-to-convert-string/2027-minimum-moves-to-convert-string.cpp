class Solution {
public:
    int minimumMoves(string s) {
        int cnt = 0;
        int i = 0;
        while(i<s.size()){
            if(s[i]=='X'){
                cnt++;
                i+=3;
            }
            else i++;
        }
        return cnt;
    }
};