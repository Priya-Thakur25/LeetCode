class Solution {
public:
    bool check(int i, int currsum, string s, int num){
        if(i >= s.length()) return currsum == num;
        if(currsum > num) return false;

        bool possible = 0;
        for(int j=i; j<s.length(); j++){
            string sub = s.substr(i, j-i+1);
            int number = stoi(sub);
            possible = possible || check(j+1,currsum+number,s,num);
            if(possible) return true;
        }
        return possible;
    }
    int punishmentNumber(int n) {
        long punish = 0;
        for(int i=1; i<=n; i++){
            int sq = i*i;
            string s = to_string(sq);
            if(check(0,0,s,i)){
                cout << punish << " ";
                punish += sq;
            }
        }
        return punish;
    }
};