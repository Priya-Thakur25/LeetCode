class Solution {
public:
   int minimumOperations(vector<int>& nums) {
        int operations = 0;

        while (nums.size() > 0) {
            // Check if remaining elements are distinct
            unordered_set<int> uniqueElements(nums.begin(), nums.end());
            if (uniqueElements.size() == nums.size()) {
                break; // Array is distinct
            }

            // Perform operation: remove the first 3 elements
            int elementsToRemove = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + elementsToRemove);
            operations++;
        }

        return operations;
    }
};