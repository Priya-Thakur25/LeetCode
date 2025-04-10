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
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
         vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2 + 1, vector<int>(k + 1, -1)));
        return solveUsingMem(0,1,k,prices,dp);
    }
};