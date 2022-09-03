class Solution {
public:
    vector<int> ans;
    void solve(int num,int n,int k){
        if(n==0){
            ans.push_back(num);
            return ;
        }
        
        int lastDigit = num%10;
        if(lastDigit-k>=0) solve(num*10+lastDigit-k,n-1,k);
        if(lastDigit+k<10 && lastDigit-k!=lastDigit+k) solve(num*10+lastDigit+k,n-1,k);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<10;i++){
            solve(i,n-1,k);
        }
        return ans;
    }
};