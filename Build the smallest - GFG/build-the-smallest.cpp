//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    string ans;
    for(int i=0;i<num.size();i++){
        while(k && ans.size() && num[i]<ans[ans.size()-1]){
            ans.pop_back();
            k--;
        }
        if(ans.size()==0 && num[i]=='0') continue; 
        ans.push_back(num[i]);
    }
    while(k && ans.size()){
        ans.pop_back();
        k--;
    }
    
    return ans.size() ? ans : "0";
}