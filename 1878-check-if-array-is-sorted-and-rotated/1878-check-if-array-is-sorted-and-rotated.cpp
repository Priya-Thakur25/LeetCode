class Solution {
public:
    bool check(vector<int>& nums) {
         int n = nums.size();
         vector<int>temp(nums.begin(), nums.end());
         int s = 0;
         int e = n-1;
         while(e-1 >= 0 && nums[e-1] <= nums[e]){
            e--;
         }

         sort(temp.begin(), temp.end());
         for(int i=s; i<n; i++){
            if(temp[i] != nums[(e%n)]) return false;
            e++;
         }
         return true;
    }
};