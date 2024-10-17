class Solution {
public:
    int maximumSwap(int num) {
        int i=0, j=0, a=-1, b=-1, index=0, value=0;
        string s = to_string(num);
        int n = s.length();
        vector<int>arr;
        for(i=0; i<n; i++){
            int digit = s[i] - '0';
            arr.push_back(digit);
        }
        int flag = 0;

        vector<int>copied(arr.begin(), arr.end());
        sort(copied.begin(), copied.end(), greater<int>());
        while(j < n){
            if(arr[j] != copied[j]){
                index = j;
                b = copied[j];
                flag = 1;
                break;
            }
            else{
                flag = 0;
                j++;
            }
        }

        if(flag == 1){
            //finding element
            for(int k=n-1; k>index; k--){
                if(arr[k] == b){
                    b = k;
                    break;
                }
            }
            swap(arr[b], arr[index]);
        }

        for(int m=0; m<arr.size(); m++){
            value = value*10 + arr[m];
        }
        return value;
    }
};