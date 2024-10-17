class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int index = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                index = i;
                break;
            }
            else if(nums[i] > target){
                index = i;
                break;
            }
            else if(i == n-1 && nums[i] != target){
                index = n;
            } 
        }

        return index;
    }
};