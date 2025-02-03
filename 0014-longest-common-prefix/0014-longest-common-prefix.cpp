class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        sort(s.begin(), s.end());
        int i=0;
        string ans = "";
        while(i < s[0].length() && i < s[n-1].length()){
            string first = s[0];
            string sec = s[n-1];
            if(first[i] != sec[i]) break;
            else ans += first[i];
            i++;
        }
        return ans;
    }
};