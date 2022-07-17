class Solution {
public:
    bool isValid(string st){
        int hyphencnt = 0;
        for(int i=0;i<st.size();i++){
            if(st[i]>='0' && st[i]<='9') return false;
            if(st[i]=='-'){
                hyphencnt++;
                if(i==0 || i==st.size()-1 || !(st[i-1]>='a' && st[i-1]<='z') || !(st[i+1]>='a' && st[i+1]<='z')) return false;
            }
            if((st[i]==',' || st[i]=='.' || st[i]=='!') && i!=st.size()-1) return false;
        }
        return hyphencnt<=1;
    }
    int countValidWords(string st) {
        int cnt = 0;
        int i=0;
        int j=0;
        while(j<st.size()){
            while(st[j]!=' ' && j!=st.size()){
                j++;
            }
            if(i!=j && isValid(st.substr(i,j-i))) cnt++;
            i = j+1;
            j++;
        }
        return cnt;
    }
};