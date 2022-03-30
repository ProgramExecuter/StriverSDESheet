// Time Complexity - O(logn), O(n) => worst case(skew tree)
// Space Complexity - O(1)

int floorInBST(TreeNode<int>* root, int x)
{
    int ans = -1;
    TreeNode<int>* tmp = root;
    
    while(tmp) {
        if(tmp->val <= x) {
            ans = tmp->val;		// This might be answer
            tmp = tmp->right;	// Check for answer in right-subtree
        }
        else {
            tmp = tmp->left;	// Check for answer in left-subtree
        }
    }
    
    return ans;
}