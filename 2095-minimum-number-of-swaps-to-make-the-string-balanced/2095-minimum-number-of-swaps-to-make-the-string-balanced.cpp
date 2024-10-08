class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int swapCount = 0;
        
        // Traverse through the string
        for (char c : s) {
            if (c == '[') {
                balance++;  // Increment for opening bracket
            } else {
                balance--;  // Decrement for closing bracket
            }
            
            // If balance becomes negative, we need a swap
            if (balance < 0) {
                swapCount++;
                balance = 1;  // Reset balance after swap
            }
        }
        
        return swapCount;
    }
};
