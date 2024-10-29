class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int i = 1, n = nums.size();
        int count = 1, ans = nums[0];
        while(i < n){
            if(nums[i-1] != nums[i]){
                count++;
                ans = nums[i];
            }
            if(count == 3)break;
            i++;
        }
        if(count != 3)return nums[0];
        else
        return ans;
    }
};