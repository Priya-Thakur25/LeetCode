class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;
        for(int i=1; i<=n; i++){
            nums.push_back(i);
        }
        for(int i=1; i<k; i++){
            next_permutation(nums.begin(), nums.end());
        }
        string s = "";
        for(int i=0; i<n; i++){
            s += ('0'+ nums[i]);
        }
        return s;
    }
};