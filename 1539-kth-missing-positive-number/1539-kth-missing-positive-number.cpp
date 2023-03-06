class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        int j = 1;
        while(k && i<arr.size()){
            if(arr[i]!=j) {
                j++;
                k--;
            }
            else{
                j++;
                i++;
            }
        }
        while(k){
            k--;
            j++;
        }
        return j-1;
    }
};