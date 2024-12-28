class Solution {
public:
void merge(vector<int>&nums, int low, int mid, int high){
    vector<int>temp;
    int i=low, j=mid+1;
    while(i <= mid && j <= high){
        if(nums[i] <= nums[j]){
            temp.push_back(nums[i]);
            i++;
        }
        else if(nums[i] > nums[j]){
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(nums[i]); i++;
    }
    while(j <= high){
        temp.push_back(nums[j]); j++;
    }

    for(int k=low; k<=high; k++){
        nums[k] = temp[k-low];
    }
}

int countPairs(vector<int>&nums, int low, int mid, int high){
    int count=0, right = mid+1;
    for(int i=low; i<=mid; i++){
        while(right <= high && nums[i] > (long long)2*nums[right]){
            right++;
        }
        count = count + (right-(mid+1));
    }

    return count;
}
int mergeSort(vector<int>&nums, int low, int high){
    if(high <= low) return 0;
    int mid = low + (high - low)/2;
    int count = 0;
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid+1, high);
    count += countPairs(nums, low, mid, high);
     merge(nums, low, mid, high);
    return count;
}
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};