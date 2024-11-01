class Solution {
public:
    int strStr(string haystack, string needle) {
        // int n1 = haystack.length();
        // int n2 = needle.length();
        int found = haystack.find(needle);
        if(found != string::npos){
            return found;
        }
        else return -1;
    }
};