class Solution {
public:
    int solve(vector<int>& coins, int n) {
        if (n == 0)
            return 0;

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int temp = 0;
            if (n - coins[i] >= 0) {
                temp = solve(coins, n - coins[i]);
                if (temp != mini) {
                    int ans = 1 + temp;
                    mini = min(mini, ans);
                }
            }
        }
        return mini;
    }

    int solveUsingMem(vector<int>& coins, int n, vector<int>& dp) {
        if (n == 0)
            return 0;

        int mini = INT_MAX;
        if (dp[n] != -1)
            return dp[n];
        for (int i = 0; i < coins.size(); i++) {
            int temp = 0;
            if (n - coins[i] >= 0) {
                temp = solveUsingMem(coins, n - coins[i], dp);
                if (temp != INT_MAX) {
                    int ans = 1 + temp;
                    mini = min(mini, ans);
                }
            }
        }
        dp[n] = mini;
        return dp[n];
    }

    int solveUsingTab(vector<int>& coins, int n) {
        vector<int> dp(n+1, INT_MAX);

        dp[0] = 0;
        for (int val = 1; val <= n; val++) {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++) {
                if (val - coins[i] >= 0) {
                    int temp = dp[val - coins[i]];
                    if (temp != INT_MAX) {
                        int ans = 1 + temp;
                        mini = min(mini, ans);
                    }
                }
            }
            dp[val] = mini;
        }
        return dp[n];
    }
        int coinChange(vector<int> & coins, int amount) {
            // int n = amount;
            // vector<int>dp(n+1,-1);
            // int ans = solveUsingMem(coins, amount, dp);
            // if(ans == INT_MAX) return -1;
            // return ans;

            int ans = solveUsingTab(coins, amount);
            if(ans == INT_MAX) return -1;
            return ans;
        }
    };