class Solution {
public:
    int missingNumber(vector<int>& nums) {
          int n = nums.size();
          int sum = 0, ans = 0;
          sum = (n*(n+1)/2);
          for(int i=0; i<n; i++){
            ans = ans+nums[i];
          }
          return abs(ans-sum);
    }
};