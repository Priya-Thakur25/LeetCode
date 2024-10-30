class Solution {
public:
void callingA(vector<int>&nums, int s, int e, int target, int& answer){
    int  mid = s + (e-s)/2;
    if(nums[mid] == target){
        answer = mid;
        return;
    }
    if(nums[s] == target){
        answer = s;
        return;
    }
    if(nums[e] == target){
        answer = e;
        return;
    }
    if(s >= e){
        if(nums[mid] != target){
            answer = -1;
            return;
        }
    }
    if(target < nums[mid]) callingA(nums,s,mid,target, answer);
    else if(target > nums[mid]) callingA(nums, mid+1, e, target, answer);
    return;
}

void FindPivotIndex(vector<int>&nums, int s, int e, int& ans){
    int mid = s + (e-s)/2;
    if(mid+1 != nums.size() && nums[mid] > nums[mid+1]){
        ans = mid;
        return;
    }
    if(s >= e) return ;
    if(nums[mid] < nums[mid+1] && nums[mid] > nums[s]){
        FindPivotIndex(nums,mid+1, e, ans);
    }
    if(nums[mid] < nums[mid+1] && nums[mid] < nums[s]){
        FindPivotIndex(nums,s,mid, ans);
    }
}
    int search(vector<int>& nums, int target) {
        int answer = -1, n = nums.size();
        int s , e , ans = -1;
        if(n == 1 && nums[0] == target)return 0;
        FindPivotIndex(nums,0,n-1, ans);
        cout << ans;
        if (ans == -1) {
            callingA(nums, 0, n - 1, target, answer);
        }
        else if(target < nums[0]){
            callingA(nums, ans+1, n-1, target, answer);
        }
        else if(target >= nums[0]){
            callingA(nums, 0, ans, target, answer);
        }
        return answer;
    }
};