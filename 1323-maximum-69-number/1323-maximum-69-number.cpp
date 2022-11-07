class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        int len = log10(num)+1;
        int n = 0;
        for(int i=1;i<=len;i++){
            int rem = num%10;
            num/=10;
            if(rem==6) n = i;
        }
        if(n==0) return temp;
        return temp + 3*pow(10,n-1);
    }
};