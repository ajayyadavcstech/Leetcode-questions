class Solution {
public:
    int compress(vector<char>& chars) {
        int len = 0;
        char ch = chars[0];
        int grp_len = 1;
        for(int i=1;i<chars.size();i++){
            if(chars[i]==chars[i-1]){
                grp_len++;
            }
            else{
                chars[len++] = ch;
                string str = to_string(grp_len);
                if(!(str.size()==1 && str[0]=='1')){
                    for(int j=0;j<str.size();j++){
                        chars[len++] = str[j];
                    }
                }
                ch = chars[i];
                grp_len = 1;
            }
        }
        chars[len++] = ch;
        string str = to_string(grp_len);
        if(!(str.size()==1 && str[0]=='1')){
            for(int j=0;j<str.size();j++){
                chars[len++] = str[j];
            }
        }
        return len;
    }
};