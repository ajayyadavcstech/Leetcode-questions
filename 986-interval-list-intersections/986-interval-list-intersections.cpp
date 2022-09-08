class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0;
        int j = 0;
        vector<vector<int>> ans;
        while(i<firstList.size() && j<secondList.size()){
            vector<int>& first = firstList[i];
            vector<int>& second = secondList[j];
            
            if(first[1]<second[0]) i++;
            else if(second[1]<first[0]) j++;
            else if(first[1]<=second[1]){
                ans.push_back({max(first[0],second[0]),first[1]});
                second[0] = first[1]+1;
                i++;
                if(second[0]>second[1]) j++;
            }
            else if(second[1]<=first[1]){
                ans.push_back({max(first[0],second[0]),second[1]});
                first[0] = second[1]+1;
                j++;
                if(first[0]>first[1]) i++;
            }
        }
        return ans;
    }
};