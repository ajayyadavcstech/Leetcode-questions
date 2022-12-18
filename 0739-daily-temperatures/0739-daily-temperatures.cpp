class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        vector<int> ans(temp.size());
        st.push(0);
        for(int i=1;i<temp.size();i++){
            while(st.size() && temp[st.top()]<temp[i]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        while(st.size()){
            ans[st.top()] = 0;
            st.pop();
        }
        return ans;
    }
};