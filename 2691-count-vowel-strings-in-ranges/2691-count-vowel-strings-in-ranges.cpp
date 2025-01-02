class Solution {
public:
bool isSafe(int i, vector<string>&words){
    string str = words[i];
    char f = str.front();
    char e = str.back();
    if((f == 'a' || f == 'e' || f == 'i' || f == 'o' || f == 'u') && (e == 'a' || e == 'e' || e == 'i' || e == 'o' || e == 'u')){
        return true;
    }
    return false;
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>prefixSum;
        int n = words.size();
        int curr = 0;
        int j = 0;
        for(int i=0; i<n; i++){
            if(isSafe(i, words)){
                curr += 1;
            }
            prefixSum.push_back(curr);
        }
        vector<int>ans;
        int len = queries.size();
        for(int i=0; i<len; i++){
            int s = queries[i][0];
            int e = queries[i][1];
            int val = prefixSum[e] - (s > 0 ? prefixSum[s - 1] : 0);
            ans.push_back(val);
        }
        return ans;
    }
};