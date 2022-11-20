class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        float n = grades.size();
        return floor((-1+sqrt(1+8*n))/2);
    }
};