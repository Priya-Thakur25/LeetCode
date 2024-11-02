class Solution {
public:
    bool isCircularSentence(string s) {
        vector<char>str;
        int n = s.length();
        int i = 0;
        while(i < n){
            if(i == 0) str.push_back(s[i]);
            if(i+1 < n && s[i+1] == ' '){
                str.push_back(s[i]);
            }
            if(i-1 >=0 && s[i-1] == ' '){
                str.push_back(s[i]);
            }
            
            i++;
        }
        str.insert(str.begin(), s[n-1]);
        int size = str.size();
        i = 0;
        while(i < size){
            if(str[i] != str[i+1]){
                return false;
            }
            i += 2;
        }
        return true;
    }
};