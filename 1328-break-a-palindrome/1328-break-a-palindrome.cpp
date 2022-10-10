class Solution {
public:
    string breakPalindrome(string st) {
        if(st.size()==1) return "";
        int i=0;
        int j=st.size()-1;
        while(i<j){
            if(st[i]!='a'){
                st[i] = 'a';
                return st;
            }
            else{
                i++;j--;
            }
        }
        st[st.size()-1]='b';
        return st;
    }
};