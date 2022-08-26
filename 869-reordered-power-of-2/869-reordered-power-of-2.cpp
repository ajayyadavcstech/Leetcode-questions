class Solution {
public:
    bool isPower(vector<int>& v,vector<int>&visited,int &sum,int ind){
        if(ind==v.size()){
            return (sum&(sum-1))==0;
        }
        
        for(int i=0 ; i<v.size();i++){
            if(visited[i]) continue;
            if(v[i]==0 && sum==0) continue;
            visited[i] = 1;
            sum = sum*10 + v[i];
            if(isPower(v,visited,sum,ind+1)) return true;
            visited[i] = 0;
            sum/=10;
        }
        return false;
    }
    
    bool reorderedPowerOf2(int n) {
        vector<int> v;
        while(n){
            int rem = n%10;
            v.push_back(rem);
            n/=10;
        }
        vector<int> visited(v.size(),0);
        int sum = 0;
        return isPower(v,visited,sum,0);
    }
};