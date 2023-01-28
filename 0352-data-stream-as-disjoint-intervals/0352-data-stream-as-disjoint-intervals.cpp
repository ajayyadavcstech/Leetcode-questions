class SummaryRanges {
public:
    vector<vector<int>> ans;
    SummaryRanges() {
        
    }
    
    int search(int num){
        int ind = -1;
        int s = 0;
        int e = ans.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(ans[mid][1]<num){
                ind = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        return ind;
    }
    void addNum(int value) {
        if(ans.size()==0) {
            ans.push_back({value,value});
            return ;
        }
        
        int ind = search(value);
        if(ind!=ans.size()-1 && value>=ans[ind+1][0] && value<=ans[ind+1][1]) return ;
        if(ind+1==ans.size()){
            if(ans[ind][1]+1==value) ans[ind][1] = value;
            else ans.push_back({value,value});
        }
        else if(ind==-1){
            if(ans[ind+1][0]-1==value) ans[ind+1][0] = value;
            else ans.insert(ans.begin()+ind+1,{value,value});
        }
        else{
            if(ans[ind][1]+1==value && ans[ind+1][0]-1==value){
                ans[ind][1] = ans[ind+1][1];
                ans.erase(ans.begin()+ind+1);
            }
            else if(ans[ind][1]+1==value){
                ans[ind][1] = value;
            }
            else if(ans[ind+1][0]-1==value) ans[ind+1][0] = value;
            else ans.insert(ans.begin()+ind+1,{value,value});
        }
    }
    
    vector<vector<int>> getIntervals() {
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */