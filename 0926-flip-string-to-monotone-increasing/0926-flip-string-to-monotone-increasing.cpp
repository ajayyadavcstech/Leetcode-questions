class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int zero = 0;
        int one = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                zero = min(zero,1+one);
                one = 1 + one;
            }
            else{
                zero = min(one,1+zero);
                one = one;
            }
        }
        return zero;
    }
};