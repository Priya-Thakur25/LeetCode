class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        string ans;
        int i=0, j=0;
        while(i < n){
            if(i<n && j<spaces.size() && i == spaces[j]){
                ans.push_back(' ');
                ans.push_back(s[i]);
                j++;
                i++;
            }
            else{
                ans.push_back(s[i]);
                i++;
            }
        }
        return ans;
    }
};