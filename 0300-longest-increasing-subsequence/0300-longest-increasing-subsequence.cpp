class Solution {
public:
    int solve(int prev, int curr, vector<int>&nums){
        if(curr >= nums.size()) return 0;

        int op1 = 0, op2 = 0;
        if(prev == -1 || nums[prev] < nums[curr]) op1 = 1 + solve(curr, curr+1, nums);
        op2 = 0 + solve(prev, curr+1, nums);
        return max(op1, op2);
    }
    int solveUsingMem(int prev, int curr, vector<int>&nums, vector<vector<int>>&dp){
        if(curr >= nums.size()) return 0;
        if(dp[prev+1][curr] != -1) return dp[prev+1][curr];
        int op1 = 0, op2 = 0;
        if(prev == -1 || nums[prev] < nums[curr]) op1 = 1 + solveUsingMem(curr, curr+1, nums, dp);
        op2 = 0 + solveUsingMem(prev, curr+1, nums, dp);
        return dp[prev+1][curr] = max(op1, op2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); 
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveUsingMem(-1,0,nums,dp);
    }
};