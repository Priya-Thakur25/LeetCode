class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(i+1 < n && nums[i] < nums[i+1]) ans += nums[i];
            else{
                ans += nums[i];
                maxi = max(maxi, ans);
                ans = 0;
            }
        }
        return maxi;
    }
};