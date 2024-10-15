class Solution {
public:
vector<string>final;
//brute force
// bool isValid(string s){
//     int count = 0;
//     for(auto ch: s){
//         if(ch == '(') count ++;
//         else if(ch == ')') count--;
//         if(count < 0) return false;
//     }
//     return count == 0;
// }
// void solve(string &s, int n){
//     if(s.length() == n*2){
//         if(isValid(s)){
//             final.push_back(s);
//         }
//         return;
//     }

//     s.push_back('(');
//     solve(s, n--);
//     s.pop_back();
//     s.push_back(')');
//     solve(s, n--);
//     s.pop_back();
// }

//optimize
void solve(string &s, int n, int open, int close){
    if(s.length() == n*2){
         final.push_back(s);
        return;
    }

    if(open < n){
        s.push_back('(');
        solve(s, n, open+1, close);
        s.pop_back();
    }

    if(close < open){
        s.push_back(')');
        solve(s, n, open, close+1);
        s.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        string s = "";
        int open = 0;
        int close = 0;
        solve(s, n, open, close);
        return final;
    }
};