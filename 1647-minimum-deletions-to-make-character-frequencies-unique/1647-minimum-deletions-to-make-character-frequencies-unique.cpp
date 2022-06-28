class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(),s.end(),greater<>());
        vector<int> fre;
        int i=0;
        while(i<s.size()){
            if(i==0 || s[i]!=s[i-1]){
                fre.push_back(1);
                i++;
            }
            else{
              fre[fre.size()-1]++;
                i++;
            }
        }
        sort(fre.begin(),fre.end(),greater<>());
        int ans = 0;
        for(int i=1;i<fre.size();i++){
            if(fre[i]>=fre[i-1]){
                int diff = fre[i-1]!=0 ? fre[i] - fre[i-1] + 1 : fre[i];
                fre[i] -= diff;
                ans+=diff;
            }
        }
        return ans;
    }
};