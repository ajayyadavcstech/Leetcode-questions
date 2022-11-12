//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	pair<int,int> fre_cnt(vector<int> &fre){
	    int mx = 0;
	    int total = 0;
	    for(auto &x : fre){
	       mx = max(mx,x);  
	       total+=x;
	    } 
	    return {mx,total-mx};
	}
	int characterReplacement(string s, int k){
	    // Code here
	    vector<int> fre(26,0);
	    int i = 0;
	    int j = 0;
	    int mx = 0;
	    while(j<s.size()){
	        fre[s[j]-'A']++;
	        pair<int,int> p = fre_cnt(fre);
	        while(p.second>k){
	            fre[s[i]-'A']--;
	            i++;
	            p  = fre_cnt(fre);
	        }
            mx = max(mx,j-i+1);
            j++;
	    }
	    return mx;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends