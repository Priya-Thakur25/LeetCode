class Solution {
public:
    // Merges two sorted halves of the array and counts reverse pairs
    int merge(vector<int>& nums, int s, int mid, int e) {
        vector<int> temp;
        int count = 0;
        int j = mid + 1;

        // Count reverse pairs
        for (int i = s; i <= mid; i++) {
            while (j <= e && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - mid - 1);
        }

        // Merge the two sorted halves
        int i = s;
        j = mid + 1;
        while (i <= mid && j <= e) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        // Add remaining elements from the left half
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        // Add remaining elements from the right half
        while (j <= e) {
            temp.push_back(nums[j]);
            j++;
        }

        // Copy the merged elements back into the original array
        for (int k = s; k <= e; k++) {
            nums[k] = temp[k - s];
        }

        return count;
    }

    // Recursive merge sort function to count reverse pairs
    int mergeSort(vector<int>& nums, int s, int e) {
        if (s >= e) return 0;

        int mid = s + (e - s) / 2;
        int count = 0;

        // Count reverse pairs in left and right halves
        count += mergeSort(nums, s, mid);
        count += mergeSort(nums, mid + 1, e);

        // Count reverse pairs across the two halves
        count += merge(nums, s, mid, e);

        return count;
    }

    // Main function to count reverse pairs in the array
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
