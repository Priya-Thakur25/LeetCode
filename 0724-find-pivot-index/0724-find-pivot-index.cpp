class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i,j,sumL=0, sumR=0, n = nums.size();
        vector<int>leftSum(n,0);
        vector<int>rightSum(n,0);
        for(i=1, j=n-2; i<n, j>=0; i++,j--){
            int Left = leftSum[i-1] + nums[i-1];
            leftSum[i] = Left;
            int Ryt = rightSum[j+1] + nums[j+1];
            rightSum[j] = Ryt  ;
        }
        for(int k=0; k<n; k++){
            if(leftSum[k] == rightSum[k]){
                return k;
            }
        }
        return -1;
    }
};