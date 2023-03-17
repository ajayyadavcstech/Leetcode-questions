class node{
  public:
    vector<node*> next;
    bool is_end ; 
    node(){
        next.resize(26,NULL);
        is_end = false;
    }
};
void Insert_into_trie(node* root,string &word,int ind){
    if(ind==word.size()){
        root->is_end = true;
        return ;
    }
    
    if(root->next[word[ind]-'a']==NULL){
        root->next[word[ind]-'a'] = new node();
    }
    Insert_into_trie(root->next[word[ind]-'a'],word,ind+1);
}
bool search_into_trie(node* root,string &word,int ind){
    if(ind==word.size()) return root->is_end;
    if(root->next[word[ind]-'a']==NULL) return false;
    return search_into_trie(root->next[word[ind]-'a'],word,ind+1);
}
bool startsWith_into_trie(node* root,string &word,int ind){
    if(ind==word.size()) return true;
    if(root->next[word[ind]-'a']==NULL) return false;
    return startsWith_into_trie(root->next[word[ind]-'a'],word,ind+1);
}
class Trie {
public:
    node* root;
    
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        Insert_into_trie(root,word,0);
    }
    
    bool search(string word) {
        return search_into_trie(root,word,0);
    }
    
    bool startsWith(string prefix) {
        return startsWith_into_trie(root,prefix,0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */