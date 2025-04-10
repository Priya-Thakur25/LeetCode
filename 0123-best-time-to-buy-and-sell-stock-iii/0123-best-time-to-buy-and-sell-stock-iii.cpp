class Solution {
public:
    int solve(int i, int buy, int most, vector<int>& prices) {
        int n = prices.size();
        if (i >= n || most == 0)
            return 0;

        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + solve(i + 1, 0, most, prices),
                         solve(i + 1, 1, most, prices));
        } else {
            profit = max(prices[i] + solve(i + 1, 1, most - 1, prices),
                         solve(i + 1, 0, most, prices));
        }

        return profit;
    }
    int solveUsingMem(int i, int buy, int most, vector<int>& prices,
                      vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        if (i >= n || most == 0)
            return 0;
        if (dp[i][buy][most] != -1)
            return dp[i][buy][most];
        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + solveUsingMem(i + 1, 0, most, prices, dp),
                         solveUsingMem(i + 1, 1, most, prices, dp));
        } else {
            profit =
                max(prices[i] + solveUsingMem(i + 1, 1, most - 1, prices, dp),
                    solveUsingMem(i + 1, 0, most, prices, dp));
        }

        return dp[i][buy][most] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(
        //     n + 1, vector<vector<int>>(2 + 1, vector<int>(2 + 1, 0)));
        // // return solveUsingMem(0,1,2,prices,dp);
        // for (int i = n; i >= 0; i--) {
        //     for (int buy = 0; buy <= 1; buy++) {
        //         for (int most = 0; most <= 2; most++) {
        //             if (i >= n || most == 0)
        //                 dp[i][buy][most] = 0;
        //             else {
        //                 int profit = 0;
        //                 if (buy) {
        //                     profit =
        //                         max(-prices[i] + dp[i + 1][0][most],
        //                             dp[i + 1][1][most]);
        //                 } else {
        //                     profit = max(
        //                         prices[i] + dp[i + 1][1][most - 1],
        //                         dp[i + 1][0][most]);
        //                 }

        //                 dp[i][buy][most] = profit;
        //             }
        //         }
        //     }
        // }
        // return dp[0][1][2];

        //SO
        vector<vector<int>>curr(2 + 1, vector<int>(2 + 1, 0));
        vector<vector<int>>next(2 + 1, vector<int>(2 + 1, 0));
        for (int i = n; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int most = 0; most <= 2; most++) {
                    if (i >= n || most == 0)
                        curr[buy][most] = 0;
                    else {
                        int profit = 0;
                        if (buy) {
                            profit =
                                max(-prices[i] + next[0][most],
                                    next[1][most]);
                        } else {
                            profit = max(
                                prices[i] + next[1][most - 1],
                                next[0][most]);
                        }

                        curr[buy][most] = profit;
                    }
                }
            }
            next = curr;
        }
        return next[1][2];
    }
};