class Solution {
public:
void solve(vector<int>&can, vector<int>temp, vector<vector<int>>&ans, int target, int sum, int index){
    if(sum >= target){
        if(sum == target) ans.push_back(temp);
        return;
    }
    if(index >= can.size()){
        return;
    }

    for(int i=index; i<can.size(); i++){
        sum += can[i];
        temp.push_back(can[i]);
        solve(can, temp, ans, target, sum, i);
        temp.pop_back();
        sum -= can[i];
    }
}
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        int n = can.size();
        solve(can, temp, ans, target, 0, 0);
        return ans;
    }
};