class node{
  public:
    char ch;
    unordered_map<char,node*> mp;
    int end=-1;
    node(char ch) {
        this->ch = ch;
    }
};
void insert(node* root,string &st,int i,int &ind){
    if(i==st.size()) {
        root->end = ind;
        return ;
    }
    if(root->mp.count(st[i])==0){
        root->mp[st[i]] = new node(st[i]);
    }
    insert(root->mp[st[i]],st,i+1,ind);
}
class Solution {
public:
    vector<string> ans;
    void solve(node* root,vector<vector<char>>&board,int i,int j,vector<vector<int>>&vis,vector<string>& words){
        if(i==-1 || i==board.size() || j==-1 || j==board[0].size() || root->ch!=board[i][j] || vis[i][j]) return ;
        if(root->end!=-1){
            ans.push_back(words[root->end]);
            root->end = -1;
        }
        vis[i][j]++;
        for(auto x : root->mp){
            solve(x.second,board,i+1,j,vis,words);            
            solve(x.second,board,i-1,j,vis,words);
            solve(x.second,board,i,j+1,vis,words);
            solve(x.second,board,i,j-1,vis,words);
        }
        vis[i][j]--;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        node* root = new node(' ');
        unordered_map<char,vector<pair<int,int>>> mp;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                mp[board[i][j]].push_back({i,j});
            }
        }
        for(int i=0;i<words.size();i++){
            insert(root,words[i],0,i);
        }
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        for(auto &x : root->mp){
            for(auto [i,j] : mp[x.second->ch]) solve(x.second,board,i,j,vis,words); 
        }
        return ans;
    }
};