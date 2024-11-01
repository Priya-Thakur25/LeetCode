class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        int i=0, j=n-1;
        string ans,s1 = strs[i];
        string s2 = strs[j];
        int n1 = s1.length(), n2 = s2.length();
        i=0,j=0;
        while(i < n1 && i < n2){
            if(s1[i] == s2[i]){
                ans.push_back(s1[i]);
            }
            else{
                break;
            }
            i++;
        }
        return ans;
    }
};