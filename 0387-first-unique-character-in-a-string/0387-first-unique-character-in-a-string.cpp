class Solution {
public:
    int firstUniqChar(string s) {
        char ch;
        int n = s.length();
        unordered_map<char,int>mapping;
        for(auto map: s){
            mapping[map]++;
        }
        for(int i=0; i<n; i++){
            if(mapping[s[i]] == 1) return i;
        }
        return -1;
    }
};