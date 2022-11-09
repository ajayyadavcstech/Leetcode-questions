class StockSpanner {
public:
    stack<int> st;
    vector<int> v;
    StockSpanner() {
        st.push(-1);
    }
    
    int next(int price) {
        v.push_back(price);
        int i = v.size()-1;
        while(st.top()!=-1 && v[st.top()]<=price){
            st.pop();
        }
        int ind = st.top();
        st.push(i);
        return i-ind;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
/*
    100 80  60  70 60  75  85
    1   1    1   2  1  4   6
    
    
    
    
 
    100  0
*/