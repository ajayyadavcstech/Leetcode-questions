class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        float pow = log2(n)/log2(4);
        return ceil(pow)==floor(pow);
    }
};