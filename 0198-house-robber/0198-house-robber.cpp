class Solution {
public:
    int solve(int i, vector<int>&nums){
        if(i >= nums.size()) return 0;
        int include = nums[i] + solve(i+2,nums);
        int exclude = 0 + solve(i+1, nums);
        return max(include,exclude);
    }
    int solveUsingMem(int i, vector<int>&nums, vector<int>&dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int include = nums[i] + solveUsingMem(i+2,nums,dp);
        int exclude = 0 + solveUsingMem(i+1,nums,dp);
        return dp[i] = max(include,exclude);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        // return solve(index,nums);
        vector<int>dp(n+1,-1);
        return solveUsingMem(index,nums,dp);
    }
};