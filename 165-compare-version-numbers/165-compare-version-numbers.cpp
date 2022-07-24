class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        while(i<version1.size() || j<version2.size()){
            int a = 0;
            int b = 0;
            if(i<version1.size()){
                int cnt = 0;
                while(i+cnt!=version1.size() && version1[i+cnt]!='.') cnt++;
                a = stoi(version1.substr(i,cnt));
                i += (cnt+1);
            }
            if(j<version2.size()){
                int cnt = 0;
                 while(j+cnt!=version2.size() && version2[j+cnt]!='.') cnt++;
                 b = stoi(version2.substr(j,cnt));
                 j += (cnt+1);
            }
            if(a>b) return 1;
            if(a<b) return -1;
        }
        return 0;
    }
};