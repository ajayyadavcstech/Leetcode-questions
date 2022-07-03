class Solution {
public:
    bool isSafe(int row,int col,vector<vector<int>> &image,int target){
        if(row==image.size() || row<0 || col==image[0].size() || col<0 || image[row][col]!=target) return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int target = image[sr][sc];
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        while(q.size()){
            pair<int,int> front = q.front();
            q.pop();
            int row = front.first;
            int col = front.second;
            image[row][col] = color;
            if(isSafe(row,col+1,image,target)){
                q.push(make_pair(row,col+1));
            }
            if(isSafe(row,col-1,image,target)){
                q.push(make_pair(row,col-1));
            }
            if(isSafe(row+1,col,image,target)){
                q.push(make_pair(row+1,col));
            }
            if(isSafe(row-1,col,image,target)){
                q.push(make_pair(row-1,col));
            }
        }
        return image;
    }
};