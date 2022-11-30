//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	
    	// Your code here
    	 int st = 0;
    	 int end = n-1;
    	 int i = 0;
    	 int mx = arr[n-1] + 1;
    	 while(st<end){
    	     int a = arr[st]%mx;
    	     int b = arr[end]%mx;
    	     arr[i] = mx*b + arr[i]%mx;
    	     i++;
    	     arr[i] = mx*a + arr[i]%mx;
    	     i++;
    	     st++;
    	     end--;
    	 }
    	 if(st==end) arr[i] = (arr[st]%mx)*mx + arr[i]%mx;
    	 for(int i=0;i<n;i++) arr[i]/=mx;
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends