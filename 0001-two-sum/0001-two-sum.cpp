class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int ans1, ans2, len = nums.size();
        vector<int>temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        int s=0, e=len-1;
        vector<int>ans;
        while(s < e){
            int add = temp[s]+temp[e];
            if(add == target){
               ans1 = temp[s];
               ans2 = temp[e];
               break;
            }
            else if(add > target){
                e--;
            }
            else if(add < target){
                s++;
            }
        }

        for(int i=0; i<len; i++){
            if(nums[i] == ans1 || nums[i] == ans2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};