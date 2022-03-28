///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(n*n), for searching 'n' times
// Space Complexity - O(n) => call stack

class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int> &inorder, int& idx, int st, int en) {
        int n = preorder.size();
        
        if(st > en  ||  idx == n)
            return NULL;
        
        TreeNode* node = new TreeNode(preorder[idx]);
        
        int i = st;
        for(; i <= en; ++i) {
            if(inorder[i] == preorder[idx])  break;
        }
        ++idx;
        
        node->left  = solve(preorder, inorder, idx, st, i-1);
        node->right = solve(preorder, inorder, idx, i+1, en);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size(), idx = 0;
        
        TreeNode* root = solve(preorder, inorder, idx, 0, n-1);
        
        return root;
    }
};





///////////////////////
///   Solution 2   ///
/////////////////////

// Time Complexity - O(n)
// Space Complexity - O(n + n) => call stack + map

// We hash inorder array to reduce time complexity

class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int> &inorder, int& idx, int st, int en, map<int, int> &inMap) {
        int n = preorder.size();
        
        if(st > en  ||  idx == n)       // Reached end of nodes
            return NULL;                // Or array is empty
        
        TreeNode* node = new TreeNode(preorder[idx]);
        
        int i = inMap[preorder[idx]];
        ++idx;
        
        // Make a sub-tree on left, using left array of inorder
        node->left  = solve(preorder, inorder, idx, st, i-1, inMap);
        
        // Make a sub-tree on right, using right array of inorder 
        node->right = solve(preorder, inorder, idx, i+1, en, inMap);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size(), idx = 0;
        map<int, int> inMap;
        
        // Hash all inorder value-pos
        for(int i = 0; i < n; ++i)      inMap[inorder[i]] = i; 
        
        TreeNode* root = solve(preorder, inorder, idx, 0, n-1, inMap);
        
        return root;
    }
};