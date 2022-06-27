/**
 * @param {string} n
 * @return {number}
 */
var minPartitions = function(n) {
    let ans = 0;
    for(let i=0;i<n.length;i++){
        ans = Math.max(ans,n[i]-'0');
    }
    return ans;
};