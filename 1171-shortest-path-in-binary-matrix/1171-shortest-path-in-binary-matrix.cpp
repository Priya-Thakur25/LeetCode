class type{
    public:
    int row;
    int col;
    int dist;
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>>visited(r,vector<bool>(c,false));
        int drow[] = {-1,-1,-1,0,1,1,1,0};
        int dcol[] = {-1,0,1,1,1,0,-1,-1};
        int ans = INT_MAX;
        queue<type>q;
        if(grid[0][0] != 0) return -1;
        q.push({0,0,0});
        visited[0][0] = true;
        while(!q.empty()){
            int row = q.front().row;
            int col = q.front().col;
            int dist = q.front().dist;
            if(row == r-1 && col == c-1) 
            ans = dist;
            q.pop();
            for(int i=0; i<8; i++){
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow >=0 && nrow < r && ncol >=0 && ncol < c && grid[nrow][ncol] == 0 && !visited[nrow][ncol]){
                    visited[nrow][ncol] = true;
                    q.push({nrow,ncol,dist+1});
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans + 1;
    }
};