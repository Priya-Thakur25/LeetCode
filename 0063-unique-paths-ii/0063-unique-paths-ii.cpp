class Solution {
public:
    int solve(int row, int col, int n, int m, vector<vector<int>>& obs) {
        if (row >= n || col >= m)
            return 0;
        if (row == n - 1 && col == m - 1 && obs[row][col] == 0)
            return 1;

        int count = 0;
        if (obs[row][col] == 0)
            count += solve(row + 1, col, n, m, obs);
        if (obs[row][col] == 0)
            count += solve(row, col + 1, n, m, obs);
        return count;
    }

    int solveUsingMem(int row, int col, int n, int m, vector<vector<int>>& obs,
                      vector<vector<int>>& dp) {
        if (row >= n || col >= m)
            return 0;
        if (row == n - 1 && col == m - 1 && obs[row][col] == 0)
            return 1;

        if (dp[row][col] != -1)
            return dp[row][col];
        int count = 0;
        if (obs[row][col] == 0)
            count += solveUsingMem(row + 1, col, n, m, obs, dp);
        if (obs[row][col] == 0)
            count += solveUsingMem(row, col + 1, n, m, obs, dp);
        return dp[row][col] = count;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        // return solve(0,0,n,m,obstacleGrid);
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        dp[n - 1][m - 1] = (obstacleGrid[n - 1][m - 1] == 0) ? 1 : 0;
        // return solveUsingMem(0,0,n,m,obstacleGrid,dp);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if (i == n - 1 && j == m - 1)
                        continue;
                        long long down = i+1 < n ? dp[i+1][j] : 0;
                        long long right = j+1 < m? dp[i][j+1] : 0;
                        dp[i][j] = down + right;
                }
            }
        }
        return dp[0][0];
    }
};