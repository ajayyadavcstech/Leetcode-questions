class BrowserHistory {
public:
    string history[5009];
    int size;
    int cur_url;
    
    BrowserHistory(string homepage) {
        history[0] = homepage;
        size = 1;
        cur_url = 0;
    }
    
    void visit(string url) {
        cur_url++;
        history[cur_url] = url;
        size = cur_url+1;
    }
    
    string back(int steps) {
        if(cur_url-steps<0) cur_url = 0;
        else cur_url = cur_url - steps;
        return history[cur_url];
    }
    
    string forward(int steps) {
        if(cur_url+steps>=size) cur_url = size-1;
        else cur_url +=steps;
        return history[cur_url];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

