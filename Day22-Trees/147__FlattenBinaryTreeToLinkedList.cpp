// Time Complexity - O(N)
// Space Complexity - O(N), call stack

class Solution {
public:
    pair<TreeNode*, TreeNode*> solve(TreeNode* root) {
        if(!root)   return {NULL, NULL};
        
        if(!root->left  &&  !root->right)       // Starting & ending nodes are same
            return {root, root};
        
        pair<TreeNode*, TreeNode*> l = solve(root->left);
        pair<TreeNode*, TreeNode*> r = solve(root->right);
        
        TreeNode *en;
        
        if(root->left  &&  root->right) {       // If both left & right are available
            root->right = l.first;              // then attach ( root -> left -> right )
            (l.second)->right = r.first;
            en = r.second;
        }
        else if(root->left) {                   // If only left is available
            root->right = l.first;              // then attach ( root -> left )
            en = l.second;
        }
        else if(root->right) {                  // If only right is available
            root->right = r.first;              // then attach ( root -> right )
            en = r.second;
        }
        
        root->left = NULL;          // Make all 'left' nodes NULL
        
        return {root, en};              // Return  { starting point(root), ending point } 
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};