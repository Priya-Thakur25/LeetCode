class Solution {
public:
int robRecursion(vector<int>&nums, int index){
    if(index >= nums.size()){
        return 0;
    }

    int option1 = nums[index] + robRecursion(nums, index+2);
    int option2 = 0 + robRecursion(nums, index+1);
    int ans = max(option1, option2);
    return ans;
}

int robMemo(vector<int>&nums, int index, vector<int>&dp){
    if(index >= nums.size()){
        return 0;
    }

    if(dp[index] != -1) return dp[index];

    int option1 = nums[index] + robMemo(nums, index+2, dp);
    int option2 = 0 + robMemo(nums, index+1, dp);
    dp[index] = max(option1, option2);
    return dp[index];
}
    int rob(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        // int ans = robRecursion(nums, index);
        // return ans;

        vector<int>dp(n,-1);
        int ans = robMemo(nums,index,dp);
        return ans;
    }
};