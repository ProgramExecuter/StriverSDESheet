// Time Complexity - O(n)
// Space Complexity - O(n), call stack

class Solution {
public:
    bool check(TreeNode* root1, TreeNode* root2) {
        if(!root1  &&  !root2)  return true;        // Both nodes are NULL
        
        // One of the nodes is NULL, while other isn't
        if((root1 && !root2)  || (root2 && !root1)) return false;
        
        if(root1->val != root2->val)    return false;
        
        bool flag1 = check(root1->left, root2->right);
        bool flag2 = check(root2->left, root1->right);
        
        return (flag1 && flag2);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        
        return check(root->left, root->right);
    }
};