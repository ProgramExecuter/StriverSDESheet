class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        if(n <= 0) {
            return 0;
        }
        // Arrays for storing highest heights until now
        // from left and right
        vector<int> left(n, 0), right(n, 0);
        left[0] = height[0];
        right[n-1] = height[n-1];
        
        for(int i=1; i<n; ++i) {
            left[i] = max(left[i-1], height[i]);
            right[n-1-i] = max(right[n-i], height[n-1-i]);
        }
        
        // Calculate water stored
        int ans = 0;
        for(int i=0; i<n; ++i) {
            // Current water height is minimum height from left and right
            int currWaterHeight = min(left[i], right[i]);
            // Water stored is current water height - current elevation
            ans += currWaterHeight - height[i];
        }
        
        return ans;
    }
};