class Solution {
public:
    class comp{
        public :
        bool operator()(pair<int,pair<int,int>>&p1,pair<int,pair<int,int>>&p2){
            return p1.first == p2.first ? p1.second.first>p2.second.first : p1.first > p2.first ;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,comp> pq;
        for(int i=0;i<matrix.size();i++){
            pq.push({matrix[i][0],{i,0}});
        }
        while(--k){
            pair<int,pair<int,int>> top = pq.top();
            pq.pop();
            if(top.second.second<matrix.size()-1) pq.push({matrix[top.second.first][top.second.second+1],{top.second.first,top.second.second+1}});
        }
        return pq.top().first;
    }
};