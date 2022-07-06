class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int pre2 =0;
        int pre1 =1;
        int cur;
        for(int i=2;i<=n;i++){
            cur = pre1+pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};