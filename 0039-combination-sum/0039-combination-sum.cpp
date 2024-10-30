class Solution {
public:
void solve(vector<int>&candidates, int index, int target, vector<int>&helper, vector<vector<int>>&ans){
    if(target < 0 || index >= candidates.size()){
        if(target == 0){
            ans.push_back(helper);
        }
        return;
    }

    if(target == 0){
        ans.push_back(helper);
        return;
    }

        helper.push_back(candidates[index]);
        solve(candidates, index, target-candidates[index], helper, ans);
        helper.pop_back();
        solve(candidates, index+1, target, helper, ans);

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>helper;
        int index = 0;
        solve(candidates, index, target, helper, ans);
        return ans;
    }
};