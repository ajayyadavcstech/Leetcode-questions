class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int i=num.size()-1;
        int carry = 0;
        while(i>=0 || k){
            int rem = k%10;
            int sum = rem+ (i>=0 ? num[i] : 0) +carry;
            ans.push_back(sum%10);
            carry = sum/10;
            k/=10;
            i--;
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};