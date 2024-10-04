class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int i = 0, j = n-1;
        int check = 0, flag = 0;
        long long ans = 0;
        sort(skill.begin(), skill.end());
        for(i=0,j=n-1; i<j; i++,j--){
            if(i==0){
                check = skill[i] + skill[j];
            }
            if((skill[i]+skill[j]) == check){
                ans = ans + (skill[i]*skill[j]);
                flag = 1;
            }
            else{
                flag = 0;
                break;
            }
        }

        if(flag == 0) return -1;
        else return ans;
    }
};