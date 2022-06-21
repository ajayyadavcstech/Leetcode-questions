class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow = 0;
        int fast = 0;
        do{
            slow = arr[slow];
            fast = arr[arr[fast]];
        }while(slow!=fast);
        slow = 0;
        while(arr[slow]!=arr[fast]){
            slow=arr[slow];
            fast = arr[fast];
        }
        return arr[fast];
    }
};