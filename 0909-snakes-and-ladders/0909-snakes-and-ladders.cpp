class Solution {
public:
    vector<bool> dp;
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> b;
        b.push_back(-1);
        int n = board.size();
        dp.resize(n*n+1,false);
        bool rev = false;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(!rev){
                    b.push_back(board[i][j]);
                } 
                else{
                    b.push_back(board[i][n-j-1]);   
                } 
            }
            rev = !rev;
        }
        int cnt = 0;
        queue<int>  q;
        q.push(1);
        dp[1] = true;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                int ind = q.front();
                if(ind==b.size()-1) return cnt;
                q.pop();
                for(int i=1;i<=6 && ind+i<b.size();i++){
                    
                    if(b[ind+i]==-1){
                        if(dp[ind+i]) continue;
                        q.push(ind+i); 
                        dp[ind+i] = true;
                    }
                    else{
                        if(dp[b[ind+i]]) continue;
                        q.push(b[ind+i]);
                        dp[b[ind+i]] = true;
                    } 
                }
            }cnt++;
        }
        return -1;
    }
};

