class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size()==1 && target[0]==1) return true;
        if(target.size()==1) return false;
        priority_queue<int> pq;
        long long totalSum = 0;
        for(auto &val : target){
            pq.push(val);
            totalSum+=val;
        }
        while(pq.top()!=1){
            int top = pq.top();
            int rem = totalSum-top;
            int preElement = top%rem;
            if(rem==1) return true;
            if(preElement==0 || top==preElement) return false;
            pq.pop();
            pq.push(preElement);
            totalSum = totalSum - top + preElement;
        }
        return true;
    }
};