class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index=0, i = 0, need=1;
        for(i=n-2; i>0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        for(i=n-1; i>0; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                reverse(nums.begin()+index+1, nums.end());
                need=0;
                break;
            }
        }

        if(need == 1) reverse(nums.begin()+index, nums.end());

    }
};