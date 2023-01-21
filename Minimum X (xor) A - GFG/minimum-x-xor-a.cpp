//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int cnt1 = 0;
        int cnt2 = 0;
        int num1 = a;
        int num2 = b;
        int x = 0;
        while(num1){
            if(num1&1) cnt1++;
            num1 = num1>>1;
        }
        while(num2){
            if(num2&1) cnt2++;
            num2 = num2>>1;
        }
        if(cnt1==cnt2) x = a;
        else if(cnt1<cnt2){
            cnt2-=cnt1;
            num1 = a;
            int i = 0;
            while(cnt2 && num1){
                if(num1&1){
                    num1 = num1>>1;
                }
                else{
                    x = x|(1<<i);
                    num1 = num1>>1;
                    cnt2--;
                }
                i++;
            }
            while(cnt2--){
                x = x|(1<<i);
                i++;
            }
            x = x|a;
        }
        else{
            cnt1-=cnt2;
            num1 = a;
            int i=0;
            while(cnt1){
                if(num1&1){
                    cnt1--;
                    x = x|(1<<i);
                    num1 = num1>>1;
                }
                else{
                  num1 = num1>>1; 
                }
                i++;
            }
            x = x^a;
        }
        return x;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends