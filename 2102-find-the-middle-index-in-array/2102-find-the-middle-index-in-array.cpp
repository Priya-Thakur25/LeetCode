class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int i,j,n = nums.size();
        vector<int>Lsum(n,0);
        vector<int>Rsum(n,0);
        for(i=1,j=n-2; i<n,j>=0; i++,j--){
            int left = Lsum[i-1] + nums[i-1];
            Lsum[i] = left;
            int ryt = Rsum[j+1] + nums[j+1];
            Rsum[j] = ryt; 
        }

        for(int k=0; k<n; k++){
            if(Lsum[k] == Rsum[k]){
                return k;
            }
        }
        return -1;
    }
};