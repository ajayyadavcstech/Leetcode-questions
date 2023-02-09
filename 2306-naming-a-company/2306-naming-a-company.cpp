class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        vector<unordered_set<string>> num_st(26);
        for(auto &x:ideas){
            num_st[x[0]-'a'].insert(x.substr(1,x.size()-1));
        }
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                unordered_set<string> temp;
                temp.insert(num_st[i].begin(),num_st[i].end());
                temp.insert(num_st[j].begin(),num_st[j].end());
                int common = num_st[i].size()+num_st[j].size()-temp.size();
                ans+=(num_st[i].size()-common)*(num_st[j].size()-common)*2;
            }
        }
        return ans;
    }
};