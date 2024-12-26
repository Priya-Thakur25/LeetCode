class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(mid <= high){
            int val = nums[mid];
            if(val == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
            else if(val == 0){
                swap(nums[mid], nums[low]);
                mid++, low++;
            }
            else mid++;
        }
    }
};