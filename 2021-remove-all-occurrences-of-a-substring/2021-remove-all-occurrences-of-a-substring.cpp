class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.length();
        while(s.find(part) != string::npos){
            int i = s.find(part);
            s.erase(i,n);
        }
        return  s;
    }
};