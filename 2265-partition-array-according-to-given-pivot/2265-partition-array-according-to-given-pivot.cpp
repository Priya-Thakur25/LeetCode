class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
         vector<int>nums1;
         vector<int>nums2;
         vector<int>nums3;
         vector<int>ans;
         int size = nums.size();
         int i = 0;
         while(i < size){
            if(nums[i] < pivot){
                nums1.push_back(nums[i]);
            }
            else if(nums[i] > pivot){
                nums2.push_back(nums[i]);
            }
            else if(nums[i] == pivot){
                nums3.push_back(nums[i]);
            }
            i++;
         }
        
        ans.insert(ans.end(),nums1.begin(),nums1.end());
        ans.insert(ans.end(),nums3.begin(),nums3.end());
        ans.insert(ans.end(),nums2.begin(),nums2.end());

        nums = ans;
         return nums;
    }
};