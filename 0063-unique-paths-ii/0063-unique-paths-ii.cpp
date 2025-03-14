class Solution {
public:
    int solve(int row, int col,int n, int m, vector<vector<int>>&obs){
        if(row >= n || col >= m) return 0;
        if(row == n-1 && col == m-1 && obs[row][col] == 0) return 1;
        
        int count = 0;
        if(obs[row][col] == 0) count += solve(row+1,col,n,m,obs);
        if(obs[row][col] == 0) count += solve(row,col+1,n,m,obs);
        return count;
    }

    int solveUsingMem(int row, int col,int n, int m, vector<vector<int>>&obs, vector<vector<int>>&dp){
        if(row >= n || col >= m) return 0;
        if(row == n-1 && col == m-1 && obs[row][col] == 0) return 1;
        
        if(dp[row][col] != -1) return dp[row][col];
        int count = 0;
        if(obs[row][col] == 0) count += solveUsingMem(row+1,col,n,m,obs,dp);
        if(obs[row][col] == 0) count += solveUsingMem(row,col+1,n,m,obs,dp);
        return dp[row][col] = count;
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        // return solve(0,0,n,m,obstacleGrid);
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solveUsingMem(0,0,n,m,obstacleGrid,dp);
    }
};