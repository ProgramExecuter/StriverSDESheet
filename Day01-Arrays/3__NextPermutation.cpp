class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int len = nums.size(), pos = -1;
        
        // Find the pos where the element is not in ascending order from back
        for(int i = len-2; i >= 0; --i) {
            if(nums[i] < nums[i+1]) {
                pos = i;
                break;
            }
        }
        
        // If there's no such point
        if(pos < 0) {
            goto xy;
        }
        
        // Find and replace the 'pos' element with
        // element just greater than it from right side of 'pos'
        for(int i = len-1; i > pos; --i) {
            if(nums[i] > nums[pos]) {
                swap(nums[i], nums[pos]);
                break;
            }
        }
        
        xy:
        // sort the right of 'pos' to make the number lowest next permutation
        sort(nums.begin()+pos+1, nums.end());
    }
};