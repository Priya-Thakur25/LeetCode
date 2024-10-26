class Solution {
public:
    string finalString(string s) {
        int len = s.length();
        int i = 0;
        string ans = "";
        while(i < len){
            char ch  = s[i];
            if(ch == 'i' && i != 0){
                reverse(ans.begin(), ans.end());
            }
            else if(ch != 'i'){
                ans.push_back(ch);
            }
            i++;
        }
        return ans;
    }
};