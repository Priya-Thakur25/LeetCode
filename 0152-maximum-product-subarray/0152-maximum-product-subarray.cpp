class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxiS = INT_MIN, suffix = 1;
        int maxiP = INT_MIN, prefix = 1;
         for(int i=0; i<n; i++){
            suffix = suffix*nums[i];
            prefix = prefix*nums[n-i-1];
            if(maxiS < suffix) maxiS = suffix;
            if(maxiP < prefix) maxiP = prefix;
            if(nums[i] == 0) suffix = 1;
            if(nums[n-i-1] == 0) prefix = 1;
         }
         return max(maxiS,maxiP);
    }
};