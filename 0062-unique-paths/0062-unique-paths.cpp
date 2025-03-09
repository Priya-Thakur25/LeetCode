class Solution {
public:
    int solve(int i, int j, int m, int n, int& count) {
        if (i > m || j > n)
            return 0;
        if (i == m - 1 && j == n - 1) {
            count++;
            return 0;
        }

        solve(i, j + 1, m, n, count);
        solve(i + 1, j, m, n, count);
        return 0;
    }
    int solveMem(int i, int j, int m, int n, vector<vector<int>>&dp) {
        if (i > m || j > n) return 0;
        if (i == m - 1 && j == n - 1) return 1;

        if(dp[i][j] != -1) return dp[i][j];
        int count = 0;
        count += solveMem(i, j + 1, m, n,dp);
        count += solveMem(i + 1, j, m, n,dp);
        return dp[i][j] = count;
    }
    int uniquePaths(int m, int n) {
        int count = 0;
        // return solveMem(0, 0, m, n);
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solveMem(0,0,m,n,dp);
    }
};