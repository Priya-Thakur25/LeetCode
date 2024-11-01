class Solution {
public:
    string makeFancyString(string s) {
        int count = 0,n = s.length();
        string ans = "";
        int i = 0;
        while(i < n){
            int last = ans.length()-1;
            if(last == -1){
                ans.push_back(s[i]);
                count++;
            }
            else if(ans[last] == s[i]){
                count++;
                if(count < 3){
                    ans.push_back(s[i]);
                }
            }
            else if(ans[last] != s[i]){
                count = 1;
                ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
    }
};