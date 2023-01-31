//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool is_substr(string &str,string&s){
      for(int i=0;(i+s.size()-1)<str.size();i++){
          bool check = true;
          for(int j=0;j<s.size();j++){
              if(str[i+j]!=s[j]){
              check = false;
              break;
              }
          }
          if(check) return true;
      }
      return false;
  }
    int minRepeats(string A, string B) {
        // code here
        string str = A;
        int cnt = 1;
        while(str.size()<B.size()){
            str+=A;
            cnt++;
        }
        if(is_substr(str,B)) return cnt;
        str+=A;
        if(is_substr(str,B)) return cnt+1;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends