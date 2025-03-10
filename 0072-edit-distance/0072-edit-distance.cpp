class Solution {
    int solve(string& w1, string& w2, int i, int j) {
        // MOST IMPORTANT BASE CASE
        if (i == w1.length())
            return w2.length() - j;
        if (j == w2.length())
            return w1.length() - i;

        int mini = 0;
        if (w1[i] == w2[j]) {
            mini = 0 + solve(w1, w2, i + 1, j + 1);
        } else {
            int opt1 = 1 + solve(w1, w2, i, j + 1);     // insert
            int opt2 = 1 + solve(w1, w2, i + 1, j);     // delete
            int opt3 = 1 + solve(w1, w2, i + 1, j + 1); // replace
            mini = min(opt1, min(opt2, opt3));
        }

        return mini;
    }
    
    int solveUsingMemo(string& w1, string& w2, int i, int j,
                       vector<vector<int>>& dp) {
        // MOST IMPORTANT BASE CASE
        if (i == w1.length())
            return w2.length() - j;
        if (j == w2.length())
            return w1.length() - i;

        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = 0;
        if (w1[i] == w2[j]) {
            mini = 0 + solveUsingMemo(w1, w2, i + 1, j + 1, dp);
        } else {
            int opt1 = 1 + solveUsingMemo(w1, w2, i, j + 1, dp);     // insert
            int opt2 = 1 + solveUsingMemo(w1, w2, i + 1, j, dp);     // delete
            int opt3 = 1 + solveUsingMemo(w1, w2, i + 1, j + 1, dp); // replace
            mini = min(opt1, min(opt2, opt3));
        }

        dp[i][j] = mini;
        return dp[i][j];
    }
    int solveUsingTab(string& w1, string& w2) {
        vector<vector<int>> dp(w1.length() + 1,
                               vector<int>(w2.length() + 1, 0));

        for (int i = 0; i < w2.length(); i++) {
            dp[w1.length()][i] = w2.length() - i;
        }
        for (int j = 0; j < w1.length(); j++) {
            dp[j][w2.length()] = w1.length() - j;
        }
        for (int i = w1.length() - 1; i >= 0; i--) {
            for (int j = w2.length() - 1; j >= 0; j--) {
                int mini = 0;
                if (w1[i] == w2[j]) {
                    mini = 0 + dp[i+1][j+1];
                } else {
                    int opt1 = 1 + dp[i][j+1]; // insert
                    int opt2 = 1 + dp[i+1][j]; // delete
                    int opt3 = 1 + dp[i+1][j+1]; // replace
                    mini = min(opt1, min(opt2, opt3));
                }
                dp[i][j] = mini;
            }
        }
        return dp[0][0];
    }

public:
    int minDistance(string word1, string word2) {
        // return solve(word1,word2,0,0);
        // vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        // return solveUsingMemo(word1,word2,0,0,dp);
        return solveUsingTab(word1, word2);
    }
};