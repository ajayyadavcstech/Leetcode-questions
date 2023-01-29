class LRUCache {
public:
    list<pair<int,int>> li;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)==0) return -1;
        list<pair<int,int>> ::iterator it = mp[key];
        li.push_front(*it);
        li.erase(it);
        mp[key] = li.begin();
        return li.front().second;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            list<pair<int,int>>::iterator it = mp[key];
            li.erase(it);
            
            li.push_front({key,value});
            mp[key] = li.begin();
        }
        else if(size==mp.size()){
            pair<int,int> it = li.back();
            li.pop_back();
            mp.erase(it.first);
            
            li.push_front({key,value});
            mp[key] = li.begin();
        }
        else{
            li.push_front({key,value});
            mp[key] = li.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */