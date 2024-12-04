class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, n1 = s.length();
        int j=0, n2 = t.length();
        if(n1 > n2) return false;
        while(i < n1){
            if(s[i] == t[j])i++;
            j++;
            if(j == n2 && i != n1) return false;
        }
        return true;
    }
};