class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0, n = intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        while(i < n){
            if(!ans.empty() && ans.back()[1] >= intervals[i][0] && ans.back()[1] >= intervals[i][1]){
                i++;
                continue;
            }
            if(!ans.empty() && ans.back()[1] >= intervals[i][0] && ans.back()[1] < intervals[i][1]){
                ans.back()[1] = intervals[i][1];
            }
            else{
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
            i++;
        }
        return ans;
    }
};