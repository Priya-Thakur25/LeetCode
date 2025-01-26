class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0; 
        int e = n-1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(s == e) return nums[s];
            if(mid-1 >= 0 && mid%2 == 1){
                if(nums[mid] != nums[mid-1]) e = mid-1;
                else s = mid+2;
            }
            else if(mid-1 >= 0 && mid%2 == 0){
                if(nums[mid] != nums[mid-1]) s = mid+1;
                else e = mid-2;
            }
        }
        return nums[e];
    }
};