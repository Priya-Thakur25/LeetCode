class Solution {
public:
int solve(int n, vector<int>&nums, vector<int>&dp){
    if(n >= nums.size()) return 0;

    if(dp[n] != -1) return dp[n];
    int inc = nums[n] + solve(n+2, nums, dp);
    int exc = 0 + solve(n+1, nums, dp);
    dp[n] = max(inc, exc);
    return dp[n];
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solve(0, nums, dp);
    }
};