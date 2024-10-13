class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min-heap to store (value, list index, element index)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        
        int maxValue = INT_MIN;  // To keep track of the maximum value in the current window
        int rangeStart = 0, rangeEnd = INT_MAX;  // To store the smallest range

        // Insert the first element from each list into the heap
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], {i, 0}});
            maxValue = max(maxValue, nums[i][0]);  // Update the maximum value
        }

        // Process the heap
        while (true) {
            auto [minValue, indices] = minHeap.top();  // Get the smallest element
            int listIndex = indices.first;  // List from which the element came
            int elementIndex = indices.second;  // Index of the element in the list
            minHeap.pop();

            // Update the range if it's smaller than the current best range
            if (maxValue - minValue < rangeEnd - rangeStart) {
                rangeStart = minValue;
                rangeEnd = maxValue;
            }

            // Move to the next element in the current list
            if (elementIndex + 1 < nums[listIndex].size()) {
                int nextValue = nums[listIndex][elementIndex + 1];
                minHeap.push({nextValue, {listIndex, elementIndex + 1}});
                maxValue = max(maxValue, nextValue);  // Update the maximum value
            } else {
                // If any list is exhausted, we are done
                break;
            }
        }

        return {rangeStart, rangeEnd};
    }
};