class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int>setting;
        int ans = 0;
        int i = 0;
        while(i < nums.size()){
            if(setting.empty()) setting.insert(nums[i]);
            else if(!setting.empty() && setting.find(nums[i]) != setting.end()) ans = nums[i];
            else setting.insert(nums[i]);
            i++;
        }
        return ans;
    }
};