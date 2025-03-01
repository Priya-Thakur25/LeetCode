class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        vector<int>ans;
        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] = 2 * nums[i];
                nums[i+1] = 0;
            }
        }
        for(int i=0; i<n; i++) if(nums[i] == 0) count++;
        for(int i=0; i<n; i++){
            if(nums[i] != 0) ans.push_back(nums[i]);
        }
        for(int i=0; i<count; i++) ans.push_back(0);
        return ans;
    }
};