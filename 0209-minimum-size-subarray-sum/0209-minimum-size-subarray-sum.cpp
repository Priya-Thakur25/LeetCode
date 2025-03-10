class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0;
        int e = 0;
        int sum = 0;
        int len = INT_MAX;
        while(e < nums.size()){
            sum += nums[e];
            while(sum >= target){
                len = min(len , e-s+1);
                sum -= nums[s];
                s++;
            }
            e++;
        }
        if(len == INT_MAX){
            return 0;
        }
        return len;
    }
};