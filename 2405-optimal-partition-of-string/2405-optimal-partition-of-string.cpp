class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int j=0;
        int ans = 1;
        while(j<s.size()){
            if(st.count(s[j])==0){
                st.insert(s[j]);
                j++;
            }
            else{
                st.clear();
                ans++;
            }
        }
        return ans;
    }
};