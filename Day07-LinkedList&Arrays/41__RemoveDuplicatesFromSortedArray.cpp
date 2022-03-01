class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        // If 0 or 1 elements then return
        if(n <= 1) {
            return n;
        }
        
        int slow = 1, prev = nums[0];
        
        for(int fast=1; fast<n; ++fast) {
            
            // If the 'fast' != 'prev'
            if(nums[fast] != prev) {
                prev = nums[fast];
                // swap
                swap(nums[slow], nums[fast]);
                // move slow to next
                ++slow;
            }
            
        }
        
        return slow;
    }
};