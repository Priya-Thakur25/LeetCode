class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, int fee) {
        if (i >= prices.size())
            return 0;

        int profit = 0;
        if (buy) {
            profit = max((-prices[i] + solve(i + 1, 0, prices, fee)),
                         solve(i + 1, 1, prices, fee));
        } else {
            profit = max((prices[i] - fee + solve(i + 1, 1, prices, fee)),
                         solve(i + 1, 0, prices, fee));
        }
        return profit;
    }
    int solveUsingMem(int i, int buy, vector<int>& prices,
                      vector<vector<int>>& dp, int fee) {
        if (i >= prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if (buy) {
            profit = max((-prices[i] + solveUsingMem(i + 1, 0, prices, dp, fee)),
                         solveUsingMem(i + 1, 1, prices, dp, fee));
        } else {
            profit = max((prices[i] - fee + solveUsingMem(i + 1, 1, prices, dp, fee)),
                         solveUsingMem(i + 1, 0, prices, dp, fee));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices , int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solveUsingMem(0,1,prices,dp, fee);
        // for (int i = n-1; i >= 0; i--) {
        //     for (int buy = 0; buy <= 1; buy++) {
        //         int profit = 0;
        //         if (buy) {
        //             profit =
        //                 max(-prices[i] + dp[i + 1][0],
        //                     dp[i + 1][1]);
        //         } else {
        //             profit =
        //                 max(prices[i] + dp[i + 1][1],
        //                     dp[i + 1][0]);
        //         }
        //         dp[i][buy] = profit;
        //     }
        // }
        // return dp[0][1];

        // vector<int>next(2,0), curr(2,0);
        // for (int i = n-1; i >= 0; i--) {
        //     for (int buy = 0; buy <= 1; buy++) {
        //         int profit = 0;
        //         if (buy) {
        //             profit =
        //                 max(-prices[i] + next[0],
        //                     next[1]);
        //         } else {
        //             profit =
        //                 max(prices[i] + next[1],
        //                     next[0]);
        //         }
        //         curr[buy] = profit;
        //     }
        //     next = curr;
        // }
        // return next[1];
    }
};