class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);        
        sort(horizontalCuts.begin(),horizontalCuts.end());

        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(),verticalCuts.end());

        int h_cut = 0;
        int v_cut = 0;
        
        for(int i=0;i<horizontalCuts.size()-1;i++){
            h_cut = max(h_cut,horizontalCuts[i+1]-horizontalCuts[i]);
        }
        for(int i=0;i<verticalCuts.size()-1;i++){
            v_cut = max(v_cut,verticalCuts[i+1]-verticalCuts[i]);
        }
        return (long long)h_cut*v_cut%1000000007;
    }
};