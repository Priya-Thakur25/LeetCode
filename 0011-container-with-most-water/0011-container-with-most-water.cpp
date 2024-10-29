class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int st = 0, ed = n-1;
        int maxi = INT_MIN;
        while(st < ed){
            int minimum = min(height[st], height[ed]);
            int diff = abs(st-ed);
            int mul = minimum*diff;
            if(maxi < mul){
                maxi = mul;
            }
            if(height[st] < height[ed]){
                st++;
            }
            else if(height[st] > height[ed]){
                ed--;
            }
            else if(height[st] == height[ed]){
                st++, ed--;
            }
        }
        return maxi;
    }
};