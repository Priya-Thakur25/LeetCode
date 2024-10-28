class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0, n = nums.size();
        for(int i=0; i<n;){
            if(nums[i] == 0){
                nums.erase(nums.begin()+i);
                count++;
                n--;
            }
            else{
                i++;
            }
        }
        cout << count << endl;
        while(count--){
            nums.push_back(0);
        }
    }
};