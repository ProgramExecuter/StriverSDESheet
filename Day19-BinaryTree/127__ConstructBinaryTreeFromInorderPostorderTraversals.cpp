// Time Complexity - O(n)
// Space Complexity - O(n)

// Same approach as Q.No - 126, just start from end of 'postorder' 

class Solution {
public:
    TreeNode* solve(vector<int>& postorder, vector<int> &inorder, int& idx, int st, int en, map<int, int> &inMap) {
        int n = postorder.size();
        
        if(st > en  ||  idx < 0)       // Reached end of nodes
            return NULL;                // Or array is empty
        
        TreeNode* node = new TreeNode(postorder[idx]);
        
        int i = inMap[postorder[idx]];
        --idx;
        
        // Make a sub-tree on right, using right array of inorder 
        node->right = solve(postorder, inorder, idx, i+1, en, inMap);
        
        // Make a sub-tree on left, using left array of inorder
        node->left  = solve(postorder, inorder, idx, st, i-1, inMap);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n-1;
        
        map<int, int> inMap;
        
        // Hash all inorder value-pos
        for(int i = 0; i < n; ++i)      inMap[inorder[i]] = i; 
        
        TreeNode* root = solve(postorder, inorder, idx, 0, n-1, inMap);
        
        return root;
    }
};