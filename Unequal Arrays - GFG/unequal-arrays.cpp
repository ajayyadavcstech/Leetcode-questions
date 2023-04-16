//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        // code here
        vector<int> a,b,c,d;
        for(int i=0;i<A.size();i++){
            if(A[i]%2==0) a.push_back(A[i]);
            else b.push_back(A[i]);
            if(B[i]%2==0) c.push_back(B[i]);
            else d.push_back(B[i]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());
        long long pos = 0;
        long long neg = 0;
        if(a.size()!=c.size() || b.size()!=d.size()) return -1;
        for(int i=0;i<a.size();i++){
            if(a[i]-c[i]>=0) pos+=(a[i]-c[i]);
            else neg+=abs(a[i]-c[i]);
        }
        for(int i=0;i<b.size();i++){
            if(b[i]-d[i]>=0) pos+=(b[i]-d[i]);
            else neg+=abs(b[i]-d[i]);
        }
        if(pos!=neg) return -1;
        return pos/2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends