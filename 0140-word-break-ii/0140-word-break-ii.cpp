class Solution {
public:
void solve(string s, set<string>setting, vector<string>&ans, int index, string helper){
    if(index >= s.length()){
        helper.pop_back();
        ans.push_back(helper);
        return;
    }
    for(int i=index; i<s.length(); i++){
        if(setting.find(s.substr(index,i-index+1)) != setting.end()){
            solve(s, setting, ans, i+1, helper+s.substr(index,i-index+1)+' ');
        }
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        string helper = "";
        set<string>setting(wordDict.begin(), wordDict.end());
        solve(s, setting, ans, 0, helper);
        return ans;
    }
};