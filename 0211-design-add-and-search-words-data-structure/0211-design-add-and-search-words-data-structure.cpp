class node{
  public:
    vector<node*> next;
    bool is_end;
    node(){
        next.resize(26,NULL);
        is_end = false;
    }
};
void addWord_into_trie(node* root,string &word,int i){
    if(i==word.size()) {
        root->is_end = true;
        return ;
    }
    
    if(root->next[word[i]-'a']==NULL){
        root->next[word[i]-'a'] = new node();
    }
    addWord_into_trie(root->next[word[i]-'a'],word,i+1);
}
bool search_into_trie(node* root,string &word,int i){
    if(i==word.size()) return root->is_end;
    
    if(word[i]!='.'){
        if(root->next[word[i]-'a']==NULL) return false;
        return search_into_trie(root->next[word[i]-'a'],word,i+1);
    }
    for(int j=0;j<26;j++){
        if(root->next[j]!=NULL && search_into_trie(root->next[j],word,i+1)) return true;
    }
    return false;
}
class WordDictionary {
public:
    node* root;
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        addWord_into_trie(root,word,0);
    }
    
    bool search(string word) {
       return search_into_trie(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */