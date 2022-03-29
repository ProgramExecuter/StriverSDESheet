// Time Complexity - O(logn)
// Space Complexity - O(logn)

// In worst case, complexities = O(n), in case of degenerate tree

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        
        while(curr) {
            if(curr->val == val) {      // Found the node
                break;
            }
            else if(curr->val < val) {  // Search in right-subtree
                curr = curr->right;
            }
            else {
                curr = curr->left;      // Search in left-subtree
            }
        }
        
        return curr;
    }
};