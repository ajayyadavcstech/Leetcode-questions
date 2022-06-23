class Solution {
public:
    static bool com(vector<int>& v1,vector<int>v2){
        return v1[1]<v2[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        sort(courses.begin(),courses.end(),com);
        int time = 0;
        int ans = 0;
        for(int i=0;i<courses.size();i++){
            int curtime = courses[i][0];
            int maxtime = courses[i][1];
            if(time+curtime<=maxtime){
                pq.push(curtime);
                time+=curtime;
                ans++;
            }
            else {
                if(pq.empty()) continue;
                if(curtime<pq.top()){
                    time-=pq.top();
                    time+=curtime;
                    pq.pop();
                    pq.push(curtime);
                }
            }
        }
        return ans;
    }
};