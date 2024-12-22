class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int i=0, n = nums.size();
        int should = n/3;
        int sum = 1;
        vector<int>ans;
        sort(nums.begin(), nums.end());
        for(i=1; i<n; i++){
            if(nums[i] == nums[i-1]) sum++;
            else if(nums[i] != nums[i-1]){
                if(sum > should)
                ans.push_back(nums[i-1]);
                sum = 1;
            }
        }
        if(sum > should) ans.push_back(nums[i-1]);
        return ans;
    }
};