class Solution {
public:
    int solveUsingMem(vector<int>&dp, int n){
        if(n == 1 || n == 2 || n == 3) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = solveUsingMem(dp,n-1) + solveUsingMem(dp,n-2);
    }
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
        // return solveUsingMem(dp,n);
        // dp[1] = 1;
        // if(n >= 2) dp[2] = 2;
        // for(int i=3; i<=n; i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];

        int first = 1, second = 2;
        if(n == 1) return first;
        else if(n == 2) return second;
        for(int i=3; i<=n; i++){
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};