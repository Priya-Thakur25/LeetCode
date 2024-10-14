class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        // Max-heap to keep track of largest elements
        std::priority_queue<int> maxHeap(nums.begin(), nums.end());
        long long score = 0;
        
        // Perform k operations
        for (int i = 0; i < k; ++i) {
            // Extract the largest element
            int largest = maxHeap.top();
            maxHeap.pop();
            
            // Add the largest element to the score
            score += largest;
            
            // Calculate the new value to be inserted back into the heap
            int newVal = std::ceil(largest / 3.0);
            
            // Insert the updated value back into the heap
            maxHeap.push(newVal);
        }
        
        return score;
    }
};