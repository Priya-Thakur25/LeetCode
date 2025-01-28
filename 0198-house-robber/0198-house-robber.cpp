class Solution {
public:
// int solve(int n, vector<int>&nums, vector<int>&dp){
//     if(n >= nums.size()) return 0;

//     if(dp[n] != -1) return dp[n];
//     int inc = nums[n] + solve(n+2, nums, dp);
//     int exc = 0 + solve(n+1, nums, dp);
//     dp[n] = max(inc, exc);
//     return dp[n];
// }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n, -1);
        // // return solve(0, nums, dp);

        // dp[n-1] = nums[n-1];
        // for(int i=n-2; i>=0; i--){
        //     int temp = 0;
        //     if(i+2 < n) temp = dp[i+2];
        //     int inc = nums[i] + temp;
        //     int exc = 0 + dp[i+1];
        //     dp[i] = max(inc, exc); 
        // }
        // return dp[0];

        //SPACE OPTIMIZATION -- curr -> prev -> next
        int prev = nums[n-1];
        int next = 0;
        int curr = 0;
        for(int i=n-2; i>=0; i--){
            int temp = 0;
            if(i+2 < n) temp = next;
            int inc = nums[i] + temp;
            int exc = 0 + prev;
            curr = max(inc, exc);
            next = prev;
            prev = curr;
        }
        return prev;
    }
};