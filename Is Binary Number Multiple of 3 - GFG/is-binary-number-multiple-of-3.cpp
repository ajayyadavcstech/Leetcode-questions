//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int power(int n,int m){
	    if(m==0) return 1;
	    if(m==1) return n;
	    if(m&1) return n*power(n,m-1)%3;
	    return power(n*n%3,m/2)%3;
	}
	int isDivisible(string s){
	    //complete the function here
	    int ans = 0;
	    int p = 0;
	    for(int i=s.size()-1;i>=0;i--){
	        if(s[i]=='0') {
	            p++;
	            continue;
	        }
	        int cur = power(2,p);
	        ans+=cur;
	        ans%=3;
	        p++;
	    }
	    return ans==0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends