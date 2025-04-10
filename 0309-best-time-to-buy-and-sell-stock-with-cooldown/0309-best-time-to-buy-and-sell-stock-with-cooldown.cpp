class Solution {
public:
    int solve(int i, int buy, vector<int>& prices) {
        int n = prices.size();
        if (i >= n)
            return 0;

        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + solve(i + 1, 0, prices),
                         solve(i + 1, 1, prices));
        } else
            profit = max(prices[i] + solve(i + 2, 1, prices),
                         solve(i + 1, 0, prices));
        return profit;
    }
    int solveUsingMem(int i, int buy, vector<int>& prices,
                      vector<vector<int>>& dp) {
        int n = prices.size();
        if (i >= n)
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + solveUsingMem(i + 1, 0, prices, dp),
                         solveUsingMem(i + 1, 1, prices, dp));
        } else
            profit = max(prices[i] + solveUsingMem(i + 2, 1, prices, dp),
                         solveUsingMem(i + 1, 0, prices, dp));
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+2, vector<int>(2+2, 0));
        // // return solveUsingMem(0,1,prices,dp);
        // for (int i = n; i >= 0; i--) {
        //     for (int buy = 0; buy <= 1; buy++) {
        //         if (i >= n)
        //             dp[i][buy] = 0;
        //         else{
        //             int profit = 0;
        //             if (buy) {
        //                 profit =
        //                     max(-prices[i] + dp[i + 1][0],
        //                         dp[i + 1][1]);
        //             } else
        //                 profit =
        //                     max(prices[i] + dp[i + 2][1],
        //                         dp[i + 1][0]);
        //              dp[i][buy] = profit;
        //         }
        //     }
        // }
        // return dp[0][1];

        vector<int>more(2+2,0);
        vector<int>next(2+2,0);
        vector<int>curr(2+2,0);
        for (int i = n; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (i >= n)
                    curr[buy] = 0;
                else{
                    int profit = 0;
                    if (buy) {
                        profit =
                            max(-prices[i] + next[0],
                                next[1]);
                    } else
                        profit =
                            max(prices[i] + more[1],
                               next[0]);
                     curr[buy] = profit;
                }
            }
            more = next;
            next = curr;
        }
        return next[1];
    }
};