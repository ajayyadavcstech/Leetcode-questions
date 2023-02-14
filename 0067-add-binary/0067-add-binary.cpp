class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i=a.size()-1;
        int j=b.size()-1;
        int carry = 0;
        while(i>=0 || j>=0){
            int sum = (i>=0 ? a[i]-'0' : 0) + (j>=0 ? b[j]-'0' : 0) + carry;
            if(sum==0){
                ans = "0" + ans;
            }
            else if(sum==1){
                carry = 0;
                ans = "1" + ans;
            }
            else if(sum==2){
                carry = 1;
                ans = "0" + ans;
            }
            else{
                carry = 1;
                ans = "1" + ans;
            }
            i--;j--;
        }
        if(carry) ans = "1" + ans;
        return ans;
    }
};