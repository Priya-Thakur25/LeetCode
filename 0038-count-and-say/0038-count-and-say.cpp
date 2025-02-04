class Solution {
public:
    string solve(int n, string ans){
        if(n <= 0) return ans;

        int count = 1;
        string temp = "";
        for(int i=1; i<ans.size(); i++){
            if(ans[i] == ans[i-1]) count++;
            else{
                temp += to_string(count) + ans[i-1];
                count = 1;
            }
        }
        temp += to_string(count) + ans.back();
        return solve(n-1,temp);
    }
    string countAndSay(int n) {
        return solve(n-1,"1");
    }
};