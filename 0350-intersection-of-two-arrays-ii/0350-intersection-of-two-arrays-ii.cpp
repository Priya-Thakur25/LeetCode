class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, n1 = nums1.size();
        int j = 0, n2 = nums2.size();
        vector<int>ans;
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                if(i < n1) i++;
            }
            else if(nums1[i] > nums2[j]){
                if(j < n2) j++;
            }
            else if(nums1[i] == nums2[j]){ 
                ans.push_back(nums1[i]);
                i++,j++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};