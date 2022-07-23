class Solution {
public:
    vector<int> ans;
    void merge(vector<pair<int,int>>&nums,int s,int e,int mid){
        int i = s;
        int j = mid+1;
        int k=0;
        vector<pair<int,int>> v(e-s+1);
        while(i<=mid && j<=e){
            if(nums[i].first<=nums[j].first){
                ans[nums[i].second]+=(j-mid-1);
                v[k++] = nums[i++];
            }
            else{
                v[k++] = nums[j++];
            }
        }
        while(i<=mid){
            ans[nums[i].second] +=(j-mid-1);
            v[k++] = nums[i++];
        }
        while(j<=e){
            v[k++] = nums[j++];
        }
        for(int i=s,k=0;i<=e;i++,k++){
            nums[i] = v[k];
        }
    }
    void mergeSort(vector<pair<int,int>> &nums,int s,int e){
        if(s>=e) return ;
        
        int mid = s + (e-s)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        
        merge(nums,s,e,mid);
        
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        ans.resize(nums.size(),0);
        mergeSort(v,0,v.size()-1);
        return ans;
    }
};