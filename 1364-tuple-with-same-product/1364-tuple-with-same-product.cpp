class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();

        // Count the occurrences of each product
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                mp[product]++;
            }
        }

        int ans = 0;
        for (auto& t : mp) {
            int count = t.second;
            if (count > 1) {
                ans += (count * (count - 1)) / 2;  // Choosing 2 pairs out of count occurrences
            }
        }

        return ans * 8;  // Each tuple has 8 permutations
    }
};
