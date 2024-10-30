class Solution {
public:
int searchL(vector<int>& nums, int target){
    int s = 0,e = nums.size()-1,mid=s+(e-s)/2;
    int ans = -1;
    while(s <= e){
        if(nums[mid] == target){
            ans = mid;
            e = mid-1;
        }
        else if(nums[mid] < target){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int searchR(vector<int>& nums, int target){
    int s = 0,e = nums.size()-1,mid=s+(e-s)/2;
    int ans = -1;
    while(s <= e){
        if(nums[mid] == target){
            ans = mid;
            s = mid+1;
        }
        else if(nums[mid] < target){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int s, e, mid = s + (e-s)/2;
        int ans = -1;
        int ans1 = searchL(nums, target);
        int ans2 = searchR(nums, target);
        return {ans1,ans2};
    }
};