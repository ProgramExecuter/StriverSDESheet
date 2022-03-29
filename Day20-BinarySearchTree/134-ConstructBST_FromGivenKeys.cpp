// Time Complexity - O(n)
// Space Complexity - O(n + n) , call stack + new nodes

class Solution {
public:
    TreeNode* util(vector<int>& nums, int l, int h) {
        if(l > h)
            return NULL;
        
        int mid = l+(h-l)/2;
        
        TreeNode* ans = new TreeNode(nums[mid]);    // Take mid as root
        ans->left = util(nums, l, mid-1);           // Make left-subtree from left-array
        ans->right = util(nums, mid+1, h);          // Make right-subree from right-array
        
        return ans;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        return util(nums, 0, n-1);
    }
};