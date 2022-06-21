class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int ans = 0;
        priority_queue<int> q;
        for(int i=0;i<h.size()-1;i++){
            int diff = h[i+1]-h[i];
            if(diff<0) {
                ans++;
                continue;
            }
           if(diff<=bricks){
               q.push(diff);
               bricks-=diff;
               ans++;
           }
            else{
                if(ladders==0) break;
                else if(q.empty()){
                    ladders--;
                    ans++;
                }
                else if(diff>=q.top()){
                    ladders--;
                    ans++;
                }else{
                    bricks+=q.top();
                    q.pop();
                    ladders--;
                    q.push(diff);
                    bricks-=diff;
                    ans++;
                }
            }
            
        }
        return ans;
    }
};