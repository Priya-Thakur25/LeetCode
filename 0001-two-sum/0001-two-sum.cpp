class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>>p;
        for(int i=0; i<nums.size(); i++){
            p.push_back({nums[i],i});
        }

        sort(p.begin(), p.end());
        int s=0, e=n-1;
        while(s < e){
            int sum = p[s].first + p[e].first;
            if(sum == target) return {p[s].second, p[e].second};
            else if(sum > target) e--;
            else s++;
        }
        return {-1,-1};
    }
};