class Solution {
public:
    int solve(vector<int>& nums, int prev, int curr) {
        if (curr >= nums.size())
            return 0;

        int op1 = 0;
        if (prev == -1 || nums[prev] < nums[curr])
            op1 = 1 + solve(nums, curr, curr + 1);
        int op2 = 0 + solve(nums, prev, curr + 1);
        return max(op1, op2);
    }

    int solveUsingMemo(vector<int>& nums, int prev, int curr,
                       vector<vector<int>>& dp) {
        if (curr >= nums.size())
            return 0;

        if (dp[prev + 1][curr] != -1)
            return dp[prev + 1][curr];
        int op1 = 0;
        if (prev == -1 || nums[prev] < nums[curr])
            op1 = 1 + solveUsingMemo(nums, curr, curr + 1, dp);
        int op2 = 0 + solveUsingMemo(nums, prev, curr + 1, dp);
        dp[prev + 1][curr] = max(op1, op2);
        return dp[prev + 1][curr];
    }

    int solveUsingTab(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr_id = n - 1; curr_id >= 0; curr_id--) {
            for (int prev_id = curr_id - 1; prev_id >= -1; prev_id--) {
                int op1 = 0;
                if (prev_id == -1 || nums[prev_id] < nums[curr_id])
                    op1 = 1 + dp[curr_id+1][curr_id + 1];
                int op2 = 0 + dp[prev_id+1][curr_id + 1];
                dp[prev_id + 1][curr_id] = max(op1, op2);
            }
        }
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // return solve(nums,-1,0);
        // vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        // return solveUsingMemo(nums,-1,0,dp);
        return solveUsingTab(nums);
    }
};