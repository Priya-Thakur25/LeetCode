class Solution {
public:

    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    void DFS(int row, int col, vector<vector<bool>>&visited, vector<vector<int>>&grid){
        visited[row][col] = true;
        for(int i=0; i<4; i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;
            if(nrow >= 0 && nrow < grid.size() && ncol >=0 && ncol < grid[0].size() && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                DFS(nrow,ncol,visited,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0; i<n; i++){
            if(!visited[0][i] && grid[0][i] == 1) DFS(0,i,visited,grid);
            if(!visited[m-1][i] && grid[m-1][i] == 1) DFS(m-1,i,visited,grid);
        }

        for(int i=0; i<m; i++){
            if(!visited[i][0] && grid[i][0] == 1) DFS(i,0,visited,grid);
            if(!visited[i][n-1] && grid[i][n-1] == 1) DFS(i,n-1,visited,grid);
        }

        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};