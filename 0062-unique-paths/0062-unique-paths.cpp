class Solution {
public:
int solve(vector<vector<int>>grid, int i, int j, int m, int n, vector<vector<int>>&dp){
    if(i == m-1 && j == n-1) return 1;
    int ans = 0;
    if(dp[i][j] != -1) return dp[i][j];
    grid[i][j] = -1;
    if(j+1 < n && grid[i][j+1] == 0) ans += solve(grid, i, j+1, m, n, dp);
    if(i+1 < m && grid[i+1][j] == 0) ans += solve(grid, i+1, j, m, n, dp);
    grid[i][j] = 0;
    dp[i][j] = ans;
    return dp[i][j];
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int count = 0;
        count = solve(grid,0, 0, m,n, dp);
        return count;
    }
};