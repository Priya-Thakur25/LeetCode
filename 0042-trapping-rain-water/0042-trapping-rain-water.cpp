class Solution {
public:
    int trap(vector<int>& height) {
        //HERE WE ARE TAKING MORE SPACE 
        // int n = height.size();
        // vector<int>prefixSum(n);
        // vector<int>suffixSum(n);
        // prefixSum[0] = height[0];
        // for(int i=1; i<n; i++){
        //     prefixSum[i] = max(prefixSum[i-1],height[i]);
        // }
        // suffixSum[n-1] = height[n-1];
        // for(int i=n-2; i>=0; i--){
        //     suffixSum[i] = max(suffixSum[i+1],height[i]);
        // }

        // int total = 0;
        // for(int i=0; i<n; i++){
        //     //ye dono se chota hona chahiye so we can write nums[i] < left && nums[i] < right
        //     int left = prefixSum[i];
        //     int right = suffixSum[i];
        //     int mini = min(left, right);
        //     total += mini - height[i];
        // }
        // return total;

        //LESS SPACE FOR THIS PROBLEM
        int total = 0, n = height.size();
        int left = height[0], right = height[n-1], l=0, r=n-1;
        while(l < r){
            if(height[l] <= height[r]){
                if(height[l] < left) total += left-height[l];
                else left = height[l];
                l++;
            }
            else{
                if(height[r] < right) total += right-height[r];
                else right = height[r];
                r--;
            }
        }
        return total;
    }
};