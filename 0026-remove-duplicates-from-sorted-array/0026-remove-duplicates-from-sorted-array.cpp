class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int>setting;
        for(int i=0; i<n; i++){
            setting.insert(nums[i]);
        }
        
        nums.clear();
        nums = {setting.begin(), setting.end()};
        return nums.size();
    }
};