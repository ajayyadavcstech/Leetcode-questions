class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tcost = 0,tgas = 0;
        int n = gas.size();
        for(int i=0;i<n;i++){
            tgas+=gas[i];
            tcost+=cost[i];
        }
        if(tcost>tgas) return -1;
        int i = 0;
        int j = 0;
        long long sum = 0; 
        while(j<n){
            sum+=gas[j];
            sum-=cost[j];
            while(i<=j && sum<0){
                sum-=gas[i];
                sum+=cost[i];
                i++;
            }
            j++;
        }
        if(i==0) return 0;
        j = 0;
        while(j<i){
            sum+=gas[j];
            sum-=cost[j];
            while(sum<0){
                sum-=gas[i];
                sum+=cost[i];
                i++;
            }
            j++;
        }
        return i;
    }
};