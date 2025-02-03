class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int sm = 0, lg = 0, maxsm = 0, maxlg = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i] < nums[i+1]){
                lg = lg+1;
                sm = 0;
                maxlg = max(lg, maxlg);
            }
            else if(nums[i] > nums[i+1]){
                sm = sm+1;
                lg = 0;
                maxsm = max(sm, maxsm);
            }
            else{
                sm = 0;
                lg = 0;
            }
        }
        return (max(maxlg, maxsm))+1;
    }
};