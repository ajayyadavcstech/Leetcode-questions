class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        set<vector<int>> st;
        sort(trees.begin(),trees.end());
        int first_x = trees[0][0];
        int last_x = trees[trees.size()-1][0];
        int i = 0;
        while(trees[i][0]!=last_x){
            int ind = i;
            double angle = INT32_MIN;
            for(int j=i+1;j<trees.size();j++){
                if(trees[j][0]==first_x) {
                    ind = j;
                    break;
                }
                double cur = atan(((double)(trees[j][1]-trees[i][1]))/(trees[j][0]-trees[i][0]));
                if(cur>angle){
                    angle = cur;
                    ind = j;
                }
            }
            i = ind;
            
            st.insert(trees[i]);
        }
        i = 0;
        while(trees[i][0]!=last_x){
            int ind = i;
            double angle = INT32_MAX;
            for(int j=i+1;j<trees.size();j++){
                if(trees[j][0]==trees[i][0]) continue;
                double cur = atan(((double)(trees[j][1]-trees[i][1]))/(trees[j][0]-trees[i][0]));
                if(cur<angle){
                    angle = cur;
                    ind = j;
                }
            }
            i = ind;
            st.insert(trees[i]);
        }
        for(auto v:trees){
            if(v[0]==first_x) st.insert(v);
            if(v[0]==last_x) st.insert(v);
        }
        vector<vector<int>> ans;
        for(auto &x:st) ans.push_back(x);
        return ans;
    }
};