class BrowserHistory {
public:
    list<string> history;
    list<string> :: iterator it;
    int cur_url;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        it = history.begin();
        cur_url = 0;
    }
    
    void visit(string url) {
        history.resize(cur_url+1);
        history.push_back(url);
        it++;
        cur_url++;
    }
    
    string back(int steps) {
        while(steps && cur_url>0){
            it--;
            steps--;
            cur_url--;
        }
        return *it;
    }
    
    string forward(int steps) {
        while(steps && cur_url<(history.size()-1)){
            it++;
            steps--;
            cur_url++;
        }
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */