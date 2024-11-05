class Solution {
public:
    int minChanges(string s) {
        string temp = s;
        int count = 0;
        for(int i=1; i<s.length(); i+=2){
            if(s[i] != s[i-1]) count++;
        }
        return count;
    }
};