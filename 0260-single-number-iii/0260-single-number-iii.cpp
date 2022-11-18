class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor = 0;
        for(auto &x :nums) Xor = Xor^x;
        int i = 0;
        int temp = Xor;
        int rem = temp&1;
        while(!rem){
            i++;
            temp = temp>>1;
            rem = temp&1;
        }
        int val = 0;
        for(auto &x:nums){
            if(x&(1<<i)) val = val^x;
        }
        return {val,Xor^val};
    }
};