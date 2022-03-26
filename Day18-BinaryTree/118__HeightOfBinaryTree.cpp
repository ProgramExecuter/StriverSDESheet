// Time Complexity - O(n)
// Space Complexity - O(1) , O(n) => for call stack
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        
        return max(l, r)+1;
    }
};