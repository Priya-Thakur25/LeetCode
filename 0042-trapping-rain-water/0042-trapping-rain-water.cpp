class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefixSum(n);
        vector<int>suffixSum(n);
        prefixSum[0] = height[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = max(prefixSum[i-1],height[i]);
        }
        suffixSum[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            suffixSum[i] = max(suffixSum[i+1],height[i]);
        }

        int total = 0;
        for(int i=0; i<n; i++){
            int left = prefixSum[i];
            int right = suffixSum[i];
            int mini = min(left, right);
            total += mini - height[i];
        }
        return total;
    }
};