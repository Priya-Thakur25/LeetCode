class Solution {
public:
    bool solve(int i, int j, string s, string p) {
        int n1 = s.length(), n2 = p.length();
        if (i >= n1 && j >= n2)
            return true;
        if (i == n1 && j < n2) {
            for (int it = j; it < n2; it++) {
                if (p[it] != '*')
                    return false;
            }
            return true;
        }
        if (i >= n1 || j >= n2)
            return false;

        bool ans = 0;
        if (s[i] == p[j] || p[j] == '?')
            ans = solve(i + 1, j + 1, s, p);
        else if (p[j] == '*') {
            ans = ((solve(i, j + 1, s, p) || solve(i + 1, j, s, p)) ||
                   solve(i + 1, j + 1, s, p));
        }
        return ans;
    }
    bool solveUsingMem(int i, int j, string& s, string& p,
                       vector<vector<int>>& dp) {
        int n1 = s.length(), n2 = p.length();
        if (i >= n1 && j >= n2)
            return true;
        if (i == n1 && j < n2) {
            for (int it = j; it < n2; it++) {
                if (p[it] != '*')
                    return false;
            }
            return true;
        }
        if (i >= n1 || j >= n2)
            return false;
        if (dp[i][j] != -1)
            return dp[i][j];

        bool ans = 0;
        if (s[i] == p[j] || p[j] == '?')
            ans = solveUsingMem(i + 1, j + 1, s, p, dp);
        else if (p[j] == '*') {
            ans = ((solveUsingMem(i, j + 1, s, p, dp) ||
                    solveUsingMem(i + 1, j, s, p, dp)) ||
                   solveUsingMem(i + 1, j + 1, s, p, dp));
        }
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        int n1 = s.length(), n2 = p.length();
        vector<vector<int>> dp(n1 + 2, vector<int>(n2 + 2, 0));
        // return solveUsingMem(0,0,s,p,dp);
        for (int i = n1; i >= 0; i--) {
            for (int j = n2; j >= 0; j--) {
                if (i >= n1 && j >= n2)
                    dp[i][j] = 1;
                else if (i == n1 && j < n2) {
                    bool flag = 1;
                    for (int it = j; it < n2; it++) {
                        if (p[it] != '*')
                            flag = 0;
                    }
                    if (flag == 1)
                        dp[i][j] = 1;
                } else if (i >= n1 || j >= n2)
                    dp[i][j] = 0;
                else {
                    bool ans = 0;
                    if (s[i] == p[j] || p[j] == '?')
                        ans = dp[i + 1][j + 1];
                    else if (p[j] == '*') {
                        ans = ((dp[i][j + 1] || dp[i + 1][j]) ||
                               dp[i + 1][j + 1]);
                    }
                    dp[i][j] = ans;
                }
            }
        }
        return dp[0][0];
    }
};