class Solution {
public:
    int strStr(string h, string n) {
        if(h.find(n) == string::npos) return -1;
        return h.find(n);
    }
};