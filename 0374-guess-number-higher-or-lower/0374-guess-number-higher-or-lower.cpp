/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
class Solution {
public:
    int guessNumber(int n) {
      int i = 1;
        int j = n;
        int ans;
        while(i<=j){
            int mid = j + (i-j)/2;
            int guess_val = guess(mid);
            if(guess_val==0) {
                ans = mid;
                break;
            }
            else if(guess_val==-1) j = mid-1;
            else i = mid+1;
        }
        return ans;
    }
};