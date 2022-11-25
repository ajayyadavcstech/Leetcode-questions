class Solution {
public:
    int mod = 1000000007;
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> left(n),right(n);
        for(int i=0;i<arr.size();i++){
            while(st.size() && arr[st.top()]>arr[i]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()){
            right[st.top()] = n;
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
             while(st.size() && arr[st.top()]>=arr[i]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()){
            left[st.top()] = -1;
            st.pop();
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            int l = i-left[i]-1;
            int r = right[i]-i-1;
            int cur = right[i]-left[i] - 1;
            ans = (ans + ((long)l*r+cur)*arr[i])%mod;
        }
        return ans;
    }
};