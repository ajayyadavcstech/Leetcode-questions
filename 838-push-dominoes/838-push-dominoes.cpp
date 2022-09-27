class Solution {
public:
    void right_left(string &st,int i,int j){
        while(i<j){
            st[i++] = 'R';
            st[j--] = 'L';
        }
    }
    void right(string &st,int i,int j){
        while(i<=j) st[i++] = 'R';
    }
    void left(string &st,int i,int j){
        while(i<=j) st[i++] = 'L';
    }
    
    string pushDominoes(string dominoes) {
        int i = 0;
        int j = 0;
        while(i<dominoes.size()){
            while(i<dominoes.size() && dominoes[i]!='.') i++;
            j = i;
            while(j<dominoes.size() && dominoes[j]=='.') j++;
            if((i==0 && j==dominoes.size()) || i==dominoes.size()){}
            else if(i==0){
                if(dominoes[j]=='L'){
                    int k = j-1;
                    while(k>=i) dominoes[k--] = 'L';
                }
            }
            else if(j==dominoes.size()){
                if(dominoes[i-1]=='R'){
                    int k = i;
                    while(k<j) dominoes[k++] = 'R';
                }
            }
            else if(dominoes[i-1]=='R' && dominoes[j]=='L'){
                right_left(dominoes,i,j-1);
            }
            else if(dominoes[i-1]=='R') right(dominoes,i,j-1);
            else if(dominoes[j]=='L') left(dominoes,i,j-1);
            i = j;
        }
        return dominoes;
    }
};