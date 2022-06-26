/**
 * @param {number[]} cardPoints
 * @param {number} k
 * @return {number}
 */
var maxScore = function(cardPoints, k) {
        k = cardPoints.length-k;
        let maxSum = 0;
        let i=0;
        let j =k;
        let totalSum = 0;
        for(let i=0;i<k;i++){
            totalSum+=cardPoints[i];
            maxSum +=cardPoints[i];
        }
        let cur = maxSum;
        while(j<cardPoints.length){
            totalSum+=cardPoints[j];
            cur = cur - cardPoints[i] + cardPoints[j];
            maxSum = Math.min(maxSum,cur);
            i++;
            j++;
        }
        return totalSum - maxSum;
};