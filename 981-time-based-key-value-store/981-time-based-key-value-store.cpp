class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>> &temp = mp[key];
        if(temp.size()==0 || temp[0].first>timestamp) return "";
        int i=0;
        int j=temp.size()-1;
        string value;
        while(i<=j){
            int mid = (i+j)/2;
            if(temp[mid].first==timestamp) return temp[mid].second;
            else if(temp[mid].first<timestamp){
                i = mid+1;
                value = temp[mid].second;
            }
            else j = mid-1;
        }
        return value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */