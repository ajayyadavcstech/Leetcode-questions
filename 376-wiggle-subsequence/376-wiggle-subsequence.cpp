class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int cnt = 0;
        stack<int> sign;
        for(int i=0;i<nums.size()-1;i++){
            int x = nums[i+1]-nums[i];
            if(sign.size()==0 && x!=0){
                sign.push(x);
            }
            else if(x>0 && sign.top()<0){
                sign.push(x);
            }
            else if(x<0 && sign.top()>0){
                sign.push(x);
            }
        }
        return sign.size()+1;
    }
};