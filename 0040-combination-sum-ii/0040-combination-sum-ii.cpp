class Solution {
public:
    void solve(vector<int>& can, int target, vector<vector<int>>&ans, vector<int>helper, int sum, int index){
        if(sum == target){
            ans.push_back(helper);
            return;
        }
        if(index >= can.size() || sum > target){
            return;
        }
        for(int i=index; i<can.size(); i++){
            if(i > index && can[i] == can[i-1]) continue;
            sum += can[i];
            helper.push_back(can[i]);
            solve(can, target, ans, helper, sum, i+1);
            helper.pop_back();
            sum -= can[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        vector<vector<int>>ans;
        sort(can.begin(), can.end());
        vector<int>helper;
        solve(can, target, ans, helper, 0, 0);
        return ans;
    }
};