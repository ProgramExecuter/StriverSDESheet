class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        // Take 3 positions for 0's, 1's and 2's
        int front = 0, mid = 0, back = n-1;
        
        // Stop before swapping last elements again
        while(mid <= back) {
            // move front, mid forward
            if(nums[mid] == 0) {
                swap(nums[front], nums[mid]);
                ++front;
                ++mid;
            }
            // move back backwards
            // don't move 'back'
            else if(nums[mid] == 2) {
                swap(nums[back], nums[mid]);
                --back;
            }
            // move 'mid' forward
            else {
                ++mid;
            }
        }
    }
};