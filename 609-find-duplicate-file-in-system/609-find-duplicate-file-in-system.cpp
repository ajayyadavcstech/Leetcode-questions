class Solution {
public:
    pair<string,string> find_in_content(string &st,int& ind){
        int i = st.find('(');
        int j = st.find(')');
        
        string st1 = st.substr(0,i);
        string st2 = st.substr(i+1,j-i-1);
        ind = ind + j + 2;
        
        return {st2,st1};
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<paths.size();i++){
            string st = paths[i];
            string root;
            int ind = st.find(' ');
            if(ind==string::npos) continue;
            root = st.substr(0,ind);
            ind++;
            
            while(ind<st.size()){
                if(st.find(' ',ind)==string::npos) break;
                string file = st.substr(ind,st.find(' ',ind)-ind);
                pair<string,string> content = find_in_content(file,ind);
                mp[content.first].push_back(root+"/"+content.second);
            }
            string file = st.substr(ind,st.size()-ind);
            pair<string,string> content = find_in_content(file,ind);
            mp[content.first].push_back(root+"/"+content.second);
        }
        vector<vector<string>> ans;
        for(auto v : mp){
            if(v.second.size()>1){
                vector<string> arr;
                for(auto x : v.second){
                    arr.push_back(x);
                }
                ans.push_back(arr);
            }
        }
        return ans;
    }
};