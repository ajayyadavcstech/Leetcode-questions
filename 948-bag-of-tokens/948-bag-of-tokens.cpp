class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i = 0;
        int j = tokens.size()-1;
        int score = 0;
        int max_score = 0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                max_score = max(score,max_score);
                i++;
            }
            else{
                if(!score) return 0;
                score--;
                power+=tokens[j];
                j--;
            }
        }
        return max_score;
    }
};