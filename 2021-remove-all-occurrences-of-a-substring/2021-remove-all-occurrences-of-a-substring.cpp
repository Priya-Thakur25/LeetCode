class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.length();
        int i = s.find(part);
        while(i != string::npos){
            s.erase(i,n);
            i = s.find(part);
        }
        return  s;
    }
};