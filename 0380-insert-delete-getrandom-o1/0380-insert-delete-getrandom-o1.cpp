class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> v;
    int n = 0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        mp[val] = n;
        v.push_back(val);
        n++;
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)==0) return false;
        int ind = mp[val];
        v[ind] = v[n-1];
        mp[v[n-1]] = ind;
        v.pop_back();
        n--;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int i = rand()%n;
        return v[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */