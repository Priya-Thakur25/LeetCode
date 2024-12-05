class Solution {
public:
    bool canChange(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // Backward pass: Start from the end
        int i = m - 1, j = n - 1;
        while (i >= 0 || j >= 0) {
            // Skip underscores in s
            while (i >= 0 && s[i] == '_') i--;
            // Skip underscores in t
            while (j >= 0 && t[j] == '_') j--;

            // If both are out of bounds, we are done
            if (i < 0 && j < 0) break;

            // If one is out of bounds, the transformation is invalid
            if (i < 0 || j < 0) return false;

            // Mismatched characters
            if (s[i] != t[j]) return false;

            // Rules for movement
            if (s[i] == 'R' && i > j) return false; // R cannot move left
            if (s[i] == 'L' && i < j) return false; // L cannot move right

            // Move both pointers
            i--;
            j--;
        }

        // Forward pass: Start from the beginning
        i = 0, j = 0;
        while (i < m || j < n) {
            // Skip underscores in s
            while (i < m && s[i] == '_') i++;
            // Skip underscores in t
            while (j < n && t[j] == '_') j++;

            // If both are out of bounds, we are done
            if (i >= m && j >= n) break;

            // If one is out of bounds, the transformation is invalid
            if (i >= m || j >= n) return false;

            // Mismatched characters
            if (s[i] != t[j]) return false;

            // Rules for movement
            if (s[i] == 'R' && i > j) return false; // R cannot move left
            if (s[i] == 'L' && i < j) return false; // L cannot move right

            // Move both pointers
            i++;
            j++;
        }

        return true;
    }
};