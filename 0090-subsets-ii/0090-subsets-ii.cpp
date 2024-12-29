class Solution {
public:
void solve(vector<int>&nums,int index, set<vector<int>>&s, vector<int>helper){
    if(index >= nums.size()){
        sort(helper.begin(),helper.end());
        s.insert(helper);
        return;
    }

    helper.push_back(nums[index]);
    solve(nums,index+1,s,helper);
    helper.pop_back();
    solve(nums,index+1, s, helper);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        vector<int>helper;
        int index=0;
        solve(nums,index,s,helper);
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};