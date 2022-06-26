class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        k = cardPoints.size()-k;
        int maxSum = 0;
        int i=0;
        int j =k;
        int totalSum = 0;
        for(int i=0;i<k;i++){
            totalSum+=cardPoints[i];
            maxSum +=cardPoints[i];
        }
        int cur = maxSum;
        while(j<cardPoints.size()){
            totalSum+=cardPoints[j];
            cur = cur - cardPoints[i] + cardPoints[j];
            maxSum = min(maxSum,cur);
            i++;
            j++;
        }
        return totalSum - maxSum;
    }
};