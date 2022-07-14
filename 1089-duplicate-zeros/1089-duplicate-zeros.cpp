class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int no_of_zeroes = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0) no_of_zeroes++;
        }
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]!=0 && i+no_of_zeroes<arr.size()){
                arr[i+no_of_zeroes] = arr[i];
            }
            if(arr[i]==0) {
                if(i+no_of_zeroes<arr.size()){
                    arr[i+no_of_zeroes] = arr[i];
                    arr[i+no_of_zeroes-1] = arr[i];
                }
                else if(i+no_of_zeroes==arr.size()) arr[i+no_of_zeroes-1] = arr[i];
                no_of_zeroes--;
            }
        }
        
    }
};