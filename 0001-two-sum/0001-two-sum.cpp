class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        int n = nums.size();
        for(int i=0; i<n; i++){
            v.push_back({nums[i],i});
        }

        sort(v.begin(), v.end());
        int st=0, ed=n-1;
        while(st < ed){
            int sum = v[st].first + v[ed].first;
            if(sum == target){
                return {v[st].second, v[ed].second};
            }
            else if(sum < target) st++;
            else ed--;
        }
        return {};
        // int ans1, ans2, len = nums.size();
        // vector<int>temp(nums.begin(), nums.end());
        // sort(temp.begin(), temp.end());
        // int s=0, e=len-1;
        // vector<int>ans;
        // while(s < e){
        //     int add = temp[s]+temp[e];
        //     if(add == target){
        //        ans1 = temp[s];
        //        ans2 = temp[e];
        //        break;
        //     }
        //     else if(add > target){
        //         e--;
        //     }
        //     else if(add < target){
        //         s++;
        //     }
        // }

        // for(int i=0; i<len; i++){
        //     if(nums[i] == ans1 || nums[i] == ans2){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;
    }
};