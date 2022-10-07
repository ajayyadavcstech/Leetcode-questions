class MyCalendarThree {
public:
    map<int,int> records;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        records[start]++;
        records[end]--;
        int cnt = 0;
        int mx = 0;
        for(auto &x : records){
            cnt+=x.second;
            mx = max(mx,cnt);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */