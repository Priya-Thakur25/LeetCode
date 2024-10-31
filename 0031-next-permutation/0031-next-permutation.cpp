class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());
        //Good Approach
        int index = -1, nextIndex = 0, n = nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if(index != -1){
            for(int i=n-1; i>index; i--){
                if(nums[i] > nums[index]){
                    nextIndex = i;
                    break;
                }
            }
            swap(nums[nextIndex], nums[index]);
            reverse(nums.begin() + index + 1, nums.end());
        }
        else{
            reverse(nums.begin(), nums.end());
        }
    }
};