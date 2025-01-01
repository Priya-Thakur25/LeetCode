class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int>prefixSum;
        vector<int>suffixSum;
        int curr = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                curr += 1;
            }
            prefixSum.push_back(curr);
            cout << curr << " ";
        }
        curr = 0;
        cout << endl;

        for(int i=n-1; i>=0; i--){
            if(s[i] == '1'){
                curr += 1;
            }
            suffixSum.push_back(curr);
            cout << curr << " ";
        }
        reverse(suffixSum.begin(), suffixSum.end());
        vector<int>sum;
        int maxi = INT_MIN;
        for(int i=0; i<n-1; i++){
            int summy = prefixSum[i] + suffixSum[i+1];
            sum.push_back(summy);
            maxi = max(maxi,summy);
        }
        return maxi;
    }
};