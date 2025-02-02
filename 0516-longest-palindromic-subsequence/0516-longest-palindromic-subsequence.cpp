class Solution {
public:
     int solveSO(string a, string b){
        vector<int>curr(a.length()+1,0);
        vector<int>next(a.length()+1,0);

        for(int j=b.length()-1; j>=0; j--){
            for(int i=a.length()-1; i>=0; i--){
                int ans = 0;
                if(a[i] == b[j]) ans = 1 + next[i+1];
                else ans = 0 + max(curr[i+1], next[i]);
                curr[i] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    
    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(a.begin(), a.end());
        return solveSO(s,a);
    }
};