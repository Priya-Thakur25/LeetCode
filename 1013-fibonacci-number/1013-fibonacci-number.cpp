class Solution {
public:
int solvingRecursion(int n){
    if(n == 0 || n == 1){
        return n;
    }

    int ans = solvingRecursion(n-1) + solvingRecursion(n-2);
    return ans;
}
int solvingMemo(int n, vector<int>&dp){
    if(n == 0 || n ==  1){
        dp[n] = n;
        
    }
    if(dp[n] != -1) return dp[n];
    dp[n] = solvingMemo(n-1, dp) + solvingMemo(n-2, dp);
    return dp[n];
}
int solvingTab(int n, vector<int>&dp){
    if(n == 0 || n == 1) return n;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int spaceOpti(int n){
    if(n == 0  || n == 1) return n;
    int prev = 0;
    int curr = 1;
    int ans;
    for(int i=2; i<=n; i++){
        ans = curr + prev;
        prev = curr;
        curr = ans;
    }
    return curr;
}
    int fib(int n) {
        // int ans = solvingRecursion(n);
        // return ans;

        // vector<int>dp(n+1, -1);
        // solvingMemo(n,dp);
        // return dp[n];

        // vector<int>dp(n+1, -1);
        // dp[0] = 0;
        // if(n > 0) dp[1] = 1;
        // solvingTab(n, dp);
        // return dp[n];

        int ans = spaceOpti(n);
        return ans;

    }
};