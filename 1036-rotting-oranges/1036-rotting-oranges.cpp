class element{
    public:
    int row;
    int col; 
    int time;
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<element>q;
        int n = grid.size();
        int m = grid[0].size();
        int freshOranges = 0, changedOran = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2) q.push({i,j,0});
                else if(grid[i][j] == 1) freshOranges++;
            }
        }

        int drow[] = {-1,0,1,0};
        int crow[] = {0,1,0,-1};
        int seconds = 0;
        while(!q.empty()){
            element ele = q.front();
            q.pop();
            int r = ele.row;
            int c = ele.col;
            int tm = ele.time;
            seconds = max(tm,seconds);
            for(int i=0; i<4; i++){
                int nrow = drow[i] + r;
                int ncol = crow[i] + c;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    if(grid[nrow][ncol] == 1 && grid[r][c] == 2){
                         q.push({nrow,ncol,tm+1});
                         grid[nrow][ncol] = 2;
                         changedOran++;
                    }
                }
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(grid[i][j] == 1) return -1;
        //     }
        // }
        if(freshOranges != changedOran) return -1;
        return seconds;
    }
};