class Solution {
public:
    int mx;
    void  solve(vector<string>&arr,int i,unordered_set<char> ch){
        if(i==arr.size()){
            mx = ch.size()>mx ? ch.size() : mx;
            return ;
        }
        solve(arr,i+1,ch);
        unordered_set<char> temp(ch);
        temp.insert(arr[i].begin(),arr[i].end());
        if(temp.size()==(ch.size()+arr[i].size())) solve(arr,i+1,temp);
    }
    int maxLength(vector<string>& arr) {
        mx = 0;
        solve(arr,0,unordered_set<char>());
        return mx;
    }
};