// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        
        TreeNode *curr = root;
        
        while(curr) {
            if(curr->left) {
                TreeNode* rM = curr->left;
                // Find rightmost Node in left subtree
                while(rM->right  &&  rM->right != curr) {
                    rM = rM->right;
                }

                // If left-subtree is already visited
                if(rM->right == curr) {
                    rM->right = NULL;           // Remove the link
                    ans.push_back(curr->val);   // Push the curr's value
                    curr = curr->right;         // Move to right
                }
                // Else link it to 'curr'
                else {
                    rM->right = curr;           // Create link to 'curr'
                    curr = curr->left;          // Move left
                }
            }
            else {
                ans.push_back(curr->val);       // Push the curr's value
                curr = curr->right;             // Move to right
            }
        }
        
        return ans;
    }
};