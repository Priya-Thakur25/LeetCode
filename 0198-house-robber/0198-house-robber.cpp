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

int robTabu(vector<int>&nums, int index, vector<int>&dp){
    if(index >= nums.size()){
        return 0;
    }

    int n = nums.size();
    dp[n-1] = nums[n-1];
    for(index=n-2; index>=0; index--){
        int option1 = nums[index] + ((index+2 >= n)? 0 : dp[index+2]);
        int option2 = 0 + dp[index+1];
        dp[index] = max(option1, option2);
    }
    return dp[0];
}

int robSpace(vector<int>&nums, int index){
    if(index >= nums.size()){
        return 0;
    }

   int n = nums.size();
   int prev = 0;
   int curr = nums[n-1];
   int next = 0;

    for(index=n-2; index>=0; index--){
        int option1 = nums[index] + (((index+2) >= n)? 0 : next);
        int option2 = 0 + curr;
        prev = max(option1, option2);

        next = curr;
        curr = prev;
    }
    return curr;
}
    int rob(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        // int ans = robRecursion(nums, index);
        // return ans;

        // vector<int>dp(n,-1);
        // int ans = robMemo(nums,index,dp);
        // int ans = robTabu(nums,index,dp);
        int ans = robSpace(nums,index);
        return ans;
    }
};