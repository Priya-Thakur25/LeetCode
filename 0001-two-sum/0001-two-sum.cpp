class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>numC(nums.begin(), nums.end());
        vector<int>ans;
        sort(nums.begin(), nums.end());
        int i = 0, j = n-1, st1 = 0, st2 = 0;
        while(i < j){
            if((nums[i] + nums[j]) == target){
                st1 = nums[i];
                st2 = nums[j];
                break;
            }
            else if((nums[i] + nums[j]) > target) j--;
            else if((nums[i] + nums[j]) < target) i++;
        }

        for(int m=0; m<n; m++){
            if(numC[m] == st1){
                ans.push_back(m);
            }
            else if(numC[m] == st2){
                ans.push_back(m);
            }
        }
        return ans;
    } 
};