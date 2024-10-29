class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> arr;
        while (i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            } else if (nums1[i] > nums2[j]) {
                arr.push_back(nums2[j]);
                j++;
            } else if (nums1[i] == nums2[j]) {
                arr.push_back(nums1[i]);
                arr.push_back(nums2[j]);
                i++, j++;
            }
        }
        if (i != m) {
            while (i < m) {
                arr.push_back(nums1[i]);
                i++;
            }
        } else if (j != n) {
            while (j < n) {
                arr.push_back(nums2[j]);
                j++;
            }
        }
        nums1.clear();
        nums1 = arr;
    }
};