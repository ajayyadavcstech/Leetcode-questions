//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	    if(A.size()<B.size()) return addBinary(B,A);
	    string ans;
	    int carry = 0;
	    int i = A.size()-1;
	    int j = B.size()-1;
	    while(j>=0 || i>=0){
	        int a = A[i]-'0';
	        int b = 0;
	        if(j>=0) b = B[j] - '0';
	        int sum = a+b+carry;
	        if(sum==0){
	            ans.push_back(0+'0');
	            carry = 0;
	        }
	        else if(sum==1){
	            ans.push_back(1+'0');
	            carry = 0;
	        }
	        else if(sum==2){
	            ans.push_back(0+'0');
	            carry = 1;
	        }
	        else{
	            ans.push_back(1+'0');
	            carry = 1;
	        }
	        i--;
	        j--;
	    }
	    if(carry) ans.push_back(1+'0');
	    while(ans[ans.size()-1]=='0') ans.pop_back();
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends