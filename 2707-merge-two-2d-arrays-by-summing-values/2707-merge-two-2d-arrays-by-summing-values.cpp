class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,vector<int>>mp;
        for(int i=0; i<nums1.size(); i++){
            mp[nums1[i][0]].push_back(nums1[i][1]);
        }
        for(int i=0; i<nums2.size(); i++){
            mp[nums2[i][0]].push_back(nums2[i][1]);
        }

        vector<vector<int>>ans;
        for(auto i: mp){
            int sum = 0;
            for(auto it: i.second){
                sum += it;
            }
            ans.push_back({i.first,sum});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};