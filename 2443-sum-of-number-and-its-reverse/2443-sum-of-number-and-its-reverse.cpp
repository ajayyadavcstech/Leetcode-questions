class Solution {
public:
    bool solve(int i,int j){
        int num = 0;
        while(j){
            int rem = j%10;
            num = num*10 + rem;
            j/=10;
        }
        return (num-i)==0;
    }
    
    bool sumOfNumberAndReverse(int num) {
        int i = 0;
        int j = num;
        while(i<=j){
            if(solve(i,j)) return true;
            i++,j--;
        }
        return false;
    }
};