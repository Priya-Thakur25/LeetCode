class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int>ans;
        for(int i=n-k; i<n; i++){
            ans.push_back(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        for(int i=0; i<k; i++){
            nums.pop_back();
        }
        reverse(nums.begin(), nums.end());
        for(int i=0; i<k; i++){
            nums.push_back(ans[i]);
        }
        reverse(nums.begin(), nums.end());
    }
};