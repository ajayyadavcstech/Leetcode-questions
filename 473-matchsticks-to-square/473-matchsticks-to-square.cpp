class Solution {
public:
    bool isSquare(int ind,vector<int>& matchsticks,vector<bool>&visited,int one_side,int n,int max_side){
        if(n==0) return true;
        if(one_side==0){
           return isSquare(0,matchsticks,visited,max_side,n-1,max_side);
        }
        if(ind==matchsticks.size()) return false;
        
        for(int i=ind;i<matchsticks.size();i++){
            if(!visited[i] && one_side-matchsticks[i]>=0){
                visited[i]=true;
                if(isSquare(i+1,matchsticks,visited,one_side-matchsticks[i],n,max_side)) return true;
                visited[i]=false;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int Total_length = 0;
        for(auto x : matchsticks) Total_length+=x;
        if(Total_length%4!=0 || matchsticks.size()<4) return false;
        int one_side = Total_length/4;
        vector<bool> visited(matchsticks.size(),false);
        
        //fill all side
         return isSquare(0,matchsticks,visited,one_side,4,one_side);
    }
};