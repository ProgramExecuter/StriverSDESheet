// Time Complexity - O(n)
// Space Complexity - O(n), call stack space

class Solution {
public:
    int util(TreeNode* root, int &ans) {
        if(!root)   return 0;
        
        int left  = util(root->left,  ans);
        int right = util(root->right, ans);
        
        if(left < 0)    left  = 0;      // Don't include in any path
        if(right < 0)   right = 0;      //  Same as above

        ans = max(ans, (root->val + left + right));
        
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        
        util(root, ans);
        
        return ans;
    }
};