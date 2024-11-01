class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //TLE
        // set<vector<int>>ans;
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     set<int>hashset;
        //     for(int j=i+1; j<n; j++){
        //         int third = -(nums[i]+nums[j]);
        //         if(hashset.find(third) != hashset.end()){
        //             vector<int>temp = {nums[i], nums[j], third};
        //             sort(temp.begin(), temp.end());
        //             ans.insert(temp);
        //         }
        //         hashset.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>>ansVec(ans.begin(), ans.end());
        // return ansVec;

        //Approach 2
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        int j=0,k=0;
        for(int i=0; i<n; i++){
            if(i-1 >= 0 && nums[i-1] == nums[i])continue;
            j=i+1;
            k=n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                     vector<int>temp = {nums[i], nums[j], nums[k]};
                     ans.push_back(temp);
                     j++,k--;
                     while(j < k && nums[j] == nums[j-1]){
                        j++;
                     }
                     while(j < k && nums[k] == nums[k+1]){
                        k--;
                     }
                }
                else if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
            }
        }
        return ans;
    }
};