///////////
// For first solution, we can store inorder traversal, and print k-th smallest from sorted array
// But, Space Complexiy becomes O(n + n), n => for array, stack space
///////////





// Time Complexity - O(logn), O(n) => worst case(skew tree)
// Space Complexity - O(n), stack space

class Solution {
public:
    void util(TreeNode* root, int &k, int &ans) {
        if(!root)   return;
        
        // Do inorder traversal
        util(root->left,  k, ans);
        
        if(--k == 0)    ans = root->val;        /// Found k-th smallest element
        
        util(root->right, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        
        util(root, k, ans);
        
        return ans;
    }
};