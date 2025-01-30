class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        reverse(s.begin(),s.end());
        int n = s.length();
        for(int i=0; i<n; i++){
            string word = "";
            while(i < n && s[i] != ' '){
                word.push_back(s[i]);
                i++;
            }

            if(word.length() > 0){
                reverse(word.begin(), word.end());
                ans = ans + word + ' ';
            }
        }
        ans.pop_back();
        return ans;
    }
};