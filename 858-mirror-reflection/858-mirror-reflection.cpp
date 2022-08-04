class Solution {
public:
    int mirrorReflection(int p, int q) {
        bool dir = false;
        bool wall = false;
        int cnt=0;
        while(cnt!=p){
            wall = !wall;
            cnt+=q;
            if(cnt>p) {
                cnt = cnt%p;
                dir = !dir;
            }
        }
        return wall ? (dir ? 0 : 1) : 2;
    }
};