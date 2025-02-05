class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        string f = s1;
        string s = s2;
        sort(f.begin(), f.end());
        sort(s.begin(),s.end());
        if(s != f) return false;
        for(int i=0; i<s1.length(); i++){
            if(s1[i] != s2[i]) count++;
            if(count > 2) return false;
        }
        return true;
    }
};