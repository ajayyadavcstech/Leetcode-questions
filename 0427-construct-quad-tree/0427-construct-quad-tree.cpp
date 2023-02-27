/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = solve(grid,rs,(rs+re)/2,cs,(cs+ce)/2);
        new_node-= NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    pair<int,int> count(vector<vector<int>>&grid,int rs,int re,int cs,int ce){
        pair<int,int> p = {0,0};
        for(int i=rs;i<=re;i++){
            for(int j=cs;j<=ce;j++){
                if(grid[i][j]==0) p.first++;
                else p.second++;
            }
        }
        return p;
    }
    Node* solve(vector<vector<int>>&grid,int rs,int re,int cs,int ce){
        pair<int,int> cnt = count(grid,rs,re,cs,ce);
        if(cnt.first==0 || cnt.second==0){
            return new Node((cnt.first ? 0 : 1),true);
        }
        
        Node* new_node = new Node(true,false);
        
        new_node->topLeft = solve(grid,rs,(rs+re)/2,cs,(cs+ce)/2);
        
        new_node->topRight = solve(grid,rs,(rs+re)/2,((cs+ce)/2)+1,ce);
        
        new_node->bottomLeft = solve(grid,((rs+re)/2)+1,re,cs,(cs+ce)/2);
        
        new_node->bottomRight = solve(grid,((rs+re)/2)+1,re,((cs+ce)/2)+1,ce);
        
        return new_node;
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid,0,grid.size()-1,0,grid.size()-1);
    }
};