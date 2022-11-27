//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    int st = -1,end = -1;
	    int i=-1,j=0;
	    long long cur = 0,sum = 0;
	    while(j<n){
	        if(a[j]>=0){
	            cur = cur + a[j];
	        }
	        else{
	            if(cur>sum){
	                st = i;
	                end = j;
	                sum = cur;
	            }
	            else if(cur==sum && (j-i)>(end-st)){
	                st = i;
	                end = j;
	            }
	            cur = 0;
	            i = j;
	        }
	        j++;
	    }
	    if(cur>sum){
            st = i;
            end = j;
            sum = cur;
        }
        else if(cur==sum && (j-i)>(end-st)){
            st = i;
            end = j;
        }
	    vector<int> ans;
	    if(end==-1 || end-st<=1) ans.push_back(-1);
	    else{
	        for(int i=st+1;i<end;i++) ans.push_back(a[i]);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends