// Time Comlexity - O(n)
// Space Complexity - O(1), O(n) => for call stack

class Solution {
public:
    int parseTree(TreeNode* root, int& ans) {
        if(!root)   return 0;
        
        int l = parseTree(root->left,  ans);
        int r = parseTree(root->right, ans);
        
        ans = max(ans, l+r);        // Maximum distance of nodes while passing through this node
        
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        
        parseTree(root, ans);
        
        return ans;
    }
};