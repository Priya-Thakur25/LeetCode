class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX, minind = -1;
        int maxi = INT_MIN, maxind = -1;
        for(int i=0; i<n; i++){
           if(nums[i] < mini){
            mini = nums[i];
            minind = i;
           }
           if(nums[i] > maxi){
            maxi = nums[i];
            maxind = i;
           }
        }

        cout << maxind << " " << minind << endl;
        int ans = 0;
        int op1 = 0, op2 = 0, op3 = 0;
        op1 = max(minind, maxind)+1;
        if(minind < maxind){
            op2 = minind+1 + n - maxind;
        }
        else op2 = maxind + 1 + n - minind;
        op3 = n-min(minind, maxind);

        return min(op1, min(op2,op3));
    }
};