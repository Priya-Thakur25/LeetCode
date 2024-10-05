class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        if (n1 > n2) return false; // If s1 is longer than s2, return false

        // Frequency count of characters in s1 and the current window in s2
        std::vector<int> s1_freq(26, 0), s2_freq(26, 0);
        
        // Count frequency of characters in s1
        for (char c : s1) {
            s1_freq[c - 'a']++;
        }

        // Initialize the frequency count for the first window of s2
        for (int i = 0; i < n1; ++i) {
            s2_freq[s2[i] - 'a']++;
        }

        // Compare frequency arrays
        if (s1_freq == s2_freq) return true;

        // Slide the window across s2
        for (int i = n1; i < n2; ++i) {
            // Add the next character to the window
            s2_freq[s2[i] - 'a']++;
            // Remove the character going out of the window
            s2_freq[s2[i - n1] - 'a']--;

            // Compare frequency arrays
            if (s1_freq == s2_freq) return true;
        }

        return false; // No permutation found in s2
    }
};
