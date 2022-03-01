class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Assign nums[0] as starting ans
        int ans = nums[0], curr = 0;
        
        // Iterate all element
        for(int ele : nums) {
            // This should be performed first
            // because atleast sum of one element is needed in ans
            
            // This also makes sure of case when all elements are < 0
            curr += ele;
            ans = max(ans, curr);
            if(curr < 0) {
                curr = 0;
            }
        }
        
        return ans;
    }
};