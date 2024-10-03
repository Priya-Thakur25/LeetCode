class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long total_sum = 0;

        // Compute the total sum of the array
        for (int num : nums) {
            total_sum += num;
        }

        // If the total sum is already divisible by p, no need to remove anything
        int remainder = total_sum % p;
        if (remainder == 0) return 0;

        // Map to store the prefix sum modulo p and the last index where it occurred
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1; // To handle the case where we remove the prefix itself

        long prefix_sum = 0;
        int min_len = n;

        // Iterate over the array to compute prefix sums
        for (int i = 0; i < n; i++) {
            prefix_sum = (prefix_sum + nums[i]) % p;

            // We are looking for a prefix_sum that gives us the remainder we need to remove
            int needed_remainder = (prefix_sum - remainder + p) % p;

            if (prefix_map.find(needed_remainder) != prefix_map.end()) {
                // If we find a valid subarray, update the minimum length
                min_len = min(min_len, i - prefix_map[needed_remainder]);
            }

            // Update the map with the current prefix_sum and its index
            prefix_map[prefix_sum] = i;
        }

        // If no subarray was found, return -1
        return min_len == n ? -1 : min_len;
    }
};
