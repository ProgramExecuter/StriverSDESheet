// Time Comlexity - O(n)
// Space Complexity - O(1), O(n) => for call stack

class Solution {
public:
    int checkBalance(TreeNode* root) {
        if(root == NULL)    return 0;
                
        int left  = checkBalance(root->left);
        int right = checkBalance(root->right);
        
        // If any of sub-tree isn't balanced then tree isn't balanced
        if(left == -1  ||  right == -1)
            return -1;
        
        int height = max(left, right) + 1;      // Height of current sub-tree
        
        // If the heights of left & right sub-trees are not more than 1 apart
        if(abs(left - right) <= 1) {
            return height;
        }
        // Height of sub-trees not same
        else {
            return -1;
        }
    }
    bool isBalanced(TreeNode* root) {
        if(checkBalance(root) >= 0)
            return true;
        return false;
    }
};