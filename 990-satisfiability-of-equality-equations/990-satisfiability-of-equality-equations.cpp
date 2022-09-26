class Solution {
public:
    vector<int> parent;
    int find_par(int a){
        if(parent[a]==a) return a;
        return find_par(parent[a]);
    }
    void make_group(int a,int b){
        int par_1 = find_par(a);
        int par_2 = find_par(b);
        parent[par_2] = par_1;
    }
    bool equationsPossible(vector<string>& equations) {
        
        for(int i=0;i<26;i++){
            parent.push_back(i);
        }
        for(auto &v : equations){
            if(v[1]=='='){
                make_group(v[0]-'a',v[3]-'a');
            }
        }
        
        for(auto &v : equations){
            if(v[1]=='!' && find_par(v[0]-'a')==find_par(v[3]-'a')) return false;
        }
        return true;
    }
};