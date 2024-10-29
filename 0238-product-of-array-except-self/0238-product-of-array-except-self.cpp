class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>Lsum(n);
        vector<int>Rsum(n);
        vector<int>ans(n);
        int  i=0, j=n-1;
        while(i < n){
            if(i == 0){
                Lsum[i] = 1;
                Rsum[j] = 1;
            }
            else{
                Lsum[i] = Lsum[i-1]*nums[i-1];
                Rsum[j] = Rsum[j+1]*nums[j+1];
            }
            i++,j--;
        }
        i = 0;
        while(i < n){
            ans[i] = Lsum[i]*Rsum[i];
            i++;
        }
        return ans;
    }
};