class Solution {
public:
    string reverseWords(string s) {
        string rev;
        string temp;
        for(int i=s.size()-1;i>=0;i--){
            temp.push_back(s[i]);
            if(s[i]==' '){
                rev = temp + rev;
                temp = "";
            }
        }
        temp.push_back(' ');
        rev = temp + rev;
        rev.pop_back();
        return rev;
    }
};