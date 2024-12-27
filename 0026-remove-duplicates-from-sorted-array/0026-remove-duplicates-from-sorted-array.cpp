class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for(int i=0; i<nums.size(); i++){
            if(i-1 >= 0 && nums[i] == nums[i-1]) continue;
            nums[j] = nums[i];
            j++;
        }
        nums.resize(j);
        return nums.size();
    }
};