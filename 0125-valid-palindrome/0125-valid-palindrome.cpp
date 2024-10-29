class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>Vchar;
        int len1 = s.length();
        for(int i=0; i<len1; i++){
            char ch = s[i];
            if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
                Vchar.push_back(ch);
            }
        }

        int len = Vchar.size(), m=0, n=len-1;
        for(m=0, n=len-1; m<=n; m++,n--){
            if(tolower(Vchar[m]) != tolower(Vchar[n])){
                return false;
            }
        }
        return true;
    }
};