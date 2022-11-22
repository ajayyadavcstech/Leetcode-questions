//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    vector<int> small(nums.size(),0),greater(nums.size(),0);
	    for(int i=0;i<nums.size();i++){
	        int cnt = 0;
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i]) cnt++;
	        }
	        small[i] = cnt;
	        cnt = 0;
	        for(int j=i;j<nums.size();j++){
	            if(nums[j]>nums[i]) cnt++;
	        }
	        greater[i] = cnt;
	    }
	    int ans = 0;
	    for(int i=0;i<nums.size();i++) ans +=(small[i]*greater[i]);
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends