class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        int a = pow(2,n-2);
        if(k<=a) return kthGrammar(n-1,k);
        if(k%2==0) return !kthGrammar(n-1,k/2);
        return kthGrammar(n-1,k/2+1);
    }
};