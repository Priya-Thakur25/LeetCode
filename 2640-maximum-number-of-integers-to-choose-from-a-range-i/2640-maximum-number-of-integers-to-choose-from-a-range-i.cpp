class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>setting;
        for(auto i: banned){
            setting.insert(i);
        }

        int sum = 0,count=0;
        for(int i=1; i<=n; i++){
            if(setting.find(i) == setting.end()){
                sum += i;
                if(sum <= maxSum) count++;
            }
        }

        return count;
    }
};