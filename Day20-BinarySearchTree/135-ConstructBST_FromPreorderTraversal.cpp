///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(n*n)
// Space Complexity - O(n), call stack

class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int st, int en) {
        if(st > en)
            return NULL;
        
        // Make first element from remaining array as 'root' node
        int num = preorder[st];
        TreeNode* node = new TreeNode(num);
        
        // Find the point from where right-subtree elements are found
        int i=st+1;
        while(i<=en && preorder[i] < num)
            ++i;
        
        node->left  = solve(preorder, st+1, i-1);
        node->right = solve(preorder, i,  en);
        
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
             
        return solve(preorder, 0, n-1);
    }
};





///////////////////////
///   Solution 2   ///
/////////////////////

// Time Complexity - O(n*logn)
// Space Complexity - O(n+n), call stack + hash-map

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size(), idx = 0;
        
        // By sorting all elements of BST, we get inorder of a BST
        vector<int> inorder;
        for(int i : preorder)    inorder.push_back(i);
        sort(inorder.begin(), inorder.end());
        
        // Hash all inorder value-pos
        map<int, int> inMap;
        for(int i = 0; i < n; ++i)      inMap[inorder[i]] = i; 
        
        
        // We get inorder & preorder, we can make BST or Binary-Tree
        TreeNode* root = solve(preorder, inorder, idx, 0, n-1, inMap);
        
        return root;
    }
};





///////////////////////
///   Solution 3   ///
/////////////////////

// Time Complexity - O(n)
// Space Complexity - O(n), call stack

class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int& idx, int ub) {
        // If we've reached end of array, or this element is out-of-bound, RETURN null
        if(idx >= preorder.size()  ||  preorder[idx] > ub)
            return NULL;
        
        int num = preorder[idx];
        TreeNode* node = new TreeNode(num);
        ++idx;
        
        node->left  = solve(preorder, idx, num);     // upper-bound of left is this value
        node->right = solve(preorder, idx, ub);      // upper-bound of right is value of 'ub'
        
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        
        return solve(preorder, idx, INT_MAX);
    }
};