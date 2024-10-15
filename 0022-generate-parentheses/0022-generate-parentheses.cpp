class Solution {
public:
vector<string>final;
bool isValid(string s){
    int count = 0;
    for(auto ch: s){
        if(ch == '(') count ++;
        else if(ch == ')') count--;
        if(count < 0) return false;
    }
    return count == 0;
}
void solve(string &s, int n){
    if(s.length() == n*2){
        if(isValid(s)){
            final.push_back(s);
        }
        return;
    }

    s.push_back('(');
    solve(s, n);
    s.pop_back();
    s.push_back(')');
    solve(s, n);
    s.pop_back();
}
    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(s, n);
        return final;
    }
};