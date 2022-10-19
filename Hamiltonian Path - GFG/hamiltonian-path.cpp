//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool solve(int node,int cnt,unordered_map<int,vector<int>>&adj,vector<int>&visited){
        visited[node]++;
        for(auto &x : adj[node]){
            if(!visited[x] && solve(x,cnt-1,adj,visited)) return true;
        }
        visited[node]--;
        if(cnt==1) return true;
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        unordered_map<int,vector<int>> adj;
        for(auto &x : Edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
       for(int i=1;i<=N;i++){
           vector<int> visited(N+1,0);
           if(solve(i,N,adj,visited)) return true;
       }
       return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends