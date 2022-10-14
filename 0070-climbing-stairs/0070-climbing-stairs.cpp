class Solution {
public:
    int climbStairs(int n) {
        int first = 1;
        int second = 1;
        for(int i=2;i<=n;i++){
            int cur = first + second;
            first = second;
            second = cur;
        }
        return second;
    }
};