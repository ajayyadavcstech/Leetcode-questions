class Solution {
public:
    bool areNumbersAscending(string s) {
        int i=0;
        int pre = -1;
        while(i<s.size()){
            while(!(s[i]>='0'&&s[i]<='9')&&i!=s.size()) i++;
            if(i==s.size())break;
            int j=i;
            while((s[j]>='0'&&s[j]<='9') && j!=s.size()) j++;
            int val = stoi(s.substr(i,j-i));
            if(val<=pre) return false;
            pre = val;
            i=j;
        }
        return true;
    }
};