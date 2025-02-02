class Solution {
public:
    int len = 0;
    int index = 0;
    bool isPalindrome(string& s, int st, int en) {
        int i = st;
        int j = en;
        while (st < en) {
            if (s[st] != s[en])
                return false;
            st++;
            en--;
        }
        return true;
    }

    int solve(string& s, int st, int en) {
        if (st > en)
            return 0;

        if (isPalindrome(s, st, en)) {
            if (len < en - st + 1) {
                index = st;
                len = en - st + 1;
            }
            return en - st + 1;
        }
        int opt1 = solve(s, st + 1, en);
        int opt2 = solve(s, st, en - 1);
        return max(opt1, opt2);
    }

    int solveUsingMem(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (isPalindrome(s, i, j)) {
            if (len < j - i + 1) {
                index = i;
                len = j - i + 1;
            }
            return j - i + 1;
        }
        int opt1 = solveUsingMem(s, i + 1, j, dp);
        int opt2 = solveUsingMem(s, i, j - 1, dp);
        dp[i][j] = max(opt1, opt2);
        return dp[i][j];
    }

    int solveUsingTab(string s) {
        int n = s.length();
        int st = 0;
        int en = n - 1;
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    if (len < j - i + 1) {
                        index = i;
                        len = j - i + 1;
                    }
                    dp[i][j] = j - i + 1;
                    continue;
                }
                int opt1 = dp[i + 1][j];
                int opt2 = dp[i][j - 1];
                dp[i][j] = max(opt1, opt2);
            }
        }
        return dp[0][n - 1];
    }

    int solveSO(string& s){
        int n = s.length();
        int st = 0;
        int en = n-1;
        vector<int>curr(n+1,0);
        vector<int>prev(n+1,0);

        for (int j = 0; j < n; j++){
            for (int i = n - 1; i >= 0; i--){
                if (isPalindrome(s, i, j)) {
                    if (len < j - i + 1) {
                        index = i;
                        len = j - i + 1;
                    }
                    curr[i] = j - i + 1;
                    continue;
                }
                int opt1 = curr[j];
                int opt2 = prev[i];
                curr[i] = max(opt1, opt2);
            }
            curr = prev;
        }
        return curr[0];
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int st = 0;
        int en = n - 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // solve(s, st, en);
        // solveUsingMem(s,st,en,dp);
        // solveUsingTab(s);
        solveSO(s);
        string ans = s.substr(index, len);
        return ans;
    }
};