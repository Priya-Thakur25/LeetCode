class Solution {
public:
    int solve(int i, int j, string& s1, string& s2){
        int n1 = s1.length(), n2 = s2.length();
        if(i == n1) return n2-j;
        if(j == n2) return n1-i;

        int ans = 0;
        if(s1[i] == s2[j]) ans = 0 + solve(i+1, j+1, s1, s2);
        else{
            int insert = 1 + solve(i,j+1,s1,s2);
            int delet = 1 + solve(i+1,j,s1,s2);
            int replace = 1 + solve(i+1, j+1, s1,s2);
            ans = min(insert,min(delet,replace));
        }

        return ans;
        
    }
    int solveUsingMem(int i, int j, string& s1, string& s2, vector<vector<int>>&dp){
        int n1 = s1.length(), n2 = s2.length();
        if(i == n1) return n2-j;
        if(j == n2) return n1-i;

        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s1[i] == s2[j]) ans = 0 + solveUsingMem(i+1, j+1, s1, s2, dp);
        else{
            int insert = 1 + solveUsingMem(i,j+1,s1,s2, dp);
            int delet = 1 + solveUsingMem(i+1,j,s1,s2, dp);
            int replace = 1 + solveUsingMem(i+1, j+1, s1,s2, dp);
            ans = min(insert,min(delet,replace));
        }

        return dp[i][j] = ans;
        
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solveUsingMem(0,0,word1,word2,dp);
    }
};