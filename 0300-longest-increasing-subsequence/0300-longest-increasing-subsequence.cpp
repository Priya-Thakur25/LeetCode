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
                    op1 = 1 + dp[curr_id + 1][curr_id + 1];
                int op2 = 0 + dp[prev_id + 1][curr_id + 1];
                dp[prev_id + 1][curr_id] = max(op1, op2);
            }
        }
        return dp[0][0];
    }

    // int solveSO(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> currCol(n + 1, 0);
    //     vector<int> prevCol(n + 1, 0);

    //     for (int curr_id = n - 1; curr_id >= 0; curr_id--) {
    //         for (int prev_id = curr_id - 1; prev_id >= -1; prev_id--) {
    //             int op1 = 0;
    //             if (prev_id == -1 || nums[prev_id] < nums[curr_id])
    //                 op1 = 1 + currCol[curr_id + 1];
    //             int op2 = 0 + currCol[curr_id + 1];
    //             prevCol[curr_id] = max(op1, op2);
    //         }
    //         prevCol = currCol;
    //     }
    //     return currCol[0];
    // }
    int solveSO(vector<int>& nums) {
    int n = nums.size();
    vector<int> currCol(n + 1, 0);
    vector<int> prevCol(n + 1, 0);

    for (int curr_id = n - 1; curr_id >= 0; curr_id--) {
        for (int prev_id = curr_id - 1; prev_id >= -1; prev_id--) {
            int op1 = 0;
            if (prev_id == -1 || nums[prev_id] < nums[curr_id])
                op1 = 1 + prevCol[curr_id + 1]; // Use prevCol (next column)

            int op2 = prevCol[prev_id + 1]; // Also from prevCol
            currCol[prev_id + 1] = max(op1, op2); // Store in currCol
        }
        prevCol = currCol; // Move to next column
    }
    return prevCol[0]; // Final answer
}

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // return solve(nums,-1,0);
        // vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        // return solveUsingMemo(nums,-1,0,dp);
        // return solveUsingTab(nums);
        // return solveSO(nums);

        vector<int>ans;
        int i=1;
        ans.push_back(nums[0]);
        while(i < n){
            if(ans.back() < nums[i]) ans.push_back(nums[i]);
            else{
                int ind = lower_bound(ans.begin(), ans.end(),nums[i]) - ans.begin();
                ans[ind] = nums[i];
            }
            i++;
        }
        return ans.size();
    }
};