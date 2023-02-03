class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string str;
        int diff = numRows*2-2;
        for(int i=0;i<numRows;i++){
            int j = i;
            while(j<s.size()){
                str.push_back(s[j]);
                if(i!=0 && i!=numRows-1 && j+diff-(i*2)<s.size()){
                    str.push_back(s[j+diff-(i*2)]);
                }
                j+=diff;
            }
        }
        return str;
    }
};