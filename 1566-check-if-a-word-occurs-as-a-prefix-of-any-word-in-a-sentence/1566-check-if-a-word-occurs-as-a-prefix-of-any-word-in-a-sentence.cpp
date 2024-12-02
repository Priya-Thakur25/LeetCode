class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        stringstream ss(s);
        string temp;
        int i = 0;
        while(getline(ss,temp,' ')){
            i++;
            if(temp.substr(0,w.length()) == w) return i;
        }
        return -1;
    }
};