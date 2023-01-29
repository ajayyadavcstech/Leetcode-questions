class LFUCache {
public:
    unordered_map<int,list<vector<int>>::iterator> keyval;
    unordered_map<int,list<vector<int>>> frelist;
    int cap;
    int min_fre=0;
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(keyval.count(key)==0) return -1;
        vector<int> data = *(keyval[key]);
        frelist[data[2]].erase(keyval[key]);
        if(frelist[min_fre].size()==0) min_fre++;
        frelist[data[2]+1].push_front({key,data[1],data[2]+1});
        keyval[key] = frelist[data[2]+1].begin();
        return data[1];
    }
    
    void put(int key, int value) {
        if(cap==0) return ;
        if(keyval.count(key)){
            vector<int> data = *(keyval[key]);
            frelist[data[2]].erase(keyval[key]);
            if(frelist[min_fre].size()==0) min_fre++;
            frelist[data[2]+1].push_front({key,value,data[2]+1});
            keyval[key] = frelist[data[2]+1].begin();
            return ;
        }
        else if(keyval.size()==cap){
            vector<int> data = frelist[min_fre].back();
            frelist[min_fre].pop_back();
            keyval.erase(data[0]);
        }
        min_fre = 1;
        frelist[1].push_front({key,value,1});
        keyval[key] = frelist[1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */