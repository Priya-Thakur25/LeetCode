class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainder_count(k, 0); // To store frequencies of remainders
        
        // Calculate remainder and store the frequencies
        for (int num : arr) {
            int remainder = ((num % k) + k) % k;  // To handle negative numbers
            remainder_count[remainder]++;
        }
        
        // Check pairs
        // 1. Check if numbers with remainder 0 can be paired (must have an even count)
        if (remainder_count[0] % 2 != 0) return false;
        
        // 2. Check if numbers with remainder i can pair with remainder (k - i)
        for (int i = 1; i <= k / 2; i++) {
            if (remainder_count[i] != remainder_count[k - i]) {
                return false;
            }
        }
        
        return true; // If all conditions are satisfied, return true
    }
};
