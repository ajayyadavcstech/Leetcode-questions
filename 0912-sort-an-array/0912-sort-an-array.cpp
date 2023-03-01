class Solution {
public:
    void merge(vector<int>&nums,int s,int mid,int e){
        vector<int> temp;
        int i=s;
        int j=mid+1;
        while(i<=mid && j<=e){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid) temp.push_back(nums[i++]);
        while(j<=e) temp.push_back(nums[j++]);
        for(int i=s;i<=e;i++){
            nums[i] = temp[i-s];
        }
    }
    void merge_sort(vector<int>&nums,int s,int e){
        if(s==e) return ;
        int mid = (s+e)/2;
        merge_sort(nums,s,mid);
        merge_sort(nums,mid+1,e);
        merge(nums,s,mid,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums,0,nums.size()-1);
        return nums;
    }
};