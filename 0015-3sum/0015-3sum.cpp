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
        set<vector<int>>ans;
        int n = nums.size();
        int j=0,k=0;
        for(int i=0; i<n; i++){
            j=i+1;
            k=n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                     vector<int>temp = {nums[i], nums[j], nums[k]};
                     ans.insert(temp);
                     j++,k--;
                }
                else if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
            }
        }
        vector<vector<int>>VecAns(ans.begin(), ans.end());
        return VecAns;
    }
};