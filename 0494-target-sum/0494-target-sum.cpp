class Solution {
public:
void solve(vector<int>&nums, int target, int helper,int& sum, int n,int i){
    if(i >= n){
        if(target == helper) sum++;
        return;
    }
    solve(nums, target, helper-nums[i], sum, n, i+1);
    solve(nums, target, helper+nums[i], sum, n, i+1);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        solve(nums,target,0,sum,n,0);
        return sum;
    }
};