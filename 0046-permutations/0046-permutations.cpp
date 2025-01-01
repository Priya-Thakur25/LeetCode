class Solution {
public:
void solve(vector<int>&nums, vector<vector<int>>&ans, int j){
    if(j >= nums.size()){
        ans.push_back(nums);
        return;
    }
     for(int i=j; i<nums.size(); i++){
        swap(nums[i],nums[j]);
        solve(nums, ans, j+1);
        swap(nums[i], nums[j]);
     }
}
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        solve(nums,ans,0);
        return ans;
    }
};