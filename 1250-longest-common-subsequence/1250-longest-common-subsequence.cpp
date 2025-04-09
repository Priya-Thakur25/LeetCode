class Solution {
public:
    int solve(int i, int j, string& text1, string& text2) {
        int n = text1.length(), m = text2.length();
        if (i >= n || j >= m)
            return 0;

        int same = 0, diff = 0;
        if (text1[i] == text2[j]) {
            same = 1 + solve(i + 1, j + 1, text1, text2);
        } else {
            int diff1 = solve(i, j + 1, text1, text2);
            int diff2 = solve(i + 1, j, text1, text2);
            diff = max(diff1, diff2);
        }
        return max(same, diff);
    }
    int solveUsingMem(int i, int j, string text1, string text2,
                      vector<vector<int>>& dp) {
        int n = text1.length(), m = text2.length();
        if (i >= n || j >= m)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int same = 0, diff = 0;
        if (text1[i] == text2[j]) {
            same = 1 + solveUsingMem(i + 1, j + 1, text1, text2, dp);
        } else {
            int diff1 = solveUsingMem(i, j + 1, text1, text2, dp);
            int diff2 = solveUsingMem(i + 1, j, text1, text2, dp);
            diff = max(diff1, diff2);
        }
        return dp[i][j] = max(same, diff);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
        // return solveUsingMem(0,0,text1,text2,dp);
        // bottom up approach
        for (int i = n-1; i >= 0; i--) {
            int same = 0, diff = 0;
            for (int j = m-1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    same = 1 + dp[i + 1][j + 1];
                } else {
                    int diff1 = dp[i][j + 1];
                    int diff2 = dp[i + 1][j];
                    diff = max(diff1, diff2);
                }
                dp[i][j] = max(same, diff);
            }
        }
        return dp[0][0];
    }
};