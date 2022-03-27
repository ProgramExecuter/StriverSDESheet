///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(n)
// Space Complexity - O(n + n), n => Extra Space, n => call stack

class Solution {
public:
    void traverse(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*> &pathP, vector<TreeNode*> &pathQ, vector<TreeNode*> &curr) {
        if(!root)       return;
        
        curr.push_back(root);       // Add it to curr's path
        
        if(root == p)
            copy(curr.begin(), curr.end(), back_inserter(pathP));
        
        if(root == q)
            copy(curr.begin(), curr.end(), back_inserter(pathQ));
        
        traverse(root->left,  p, q, pathP, pathQ, curr);
        traverse(root->right, p, q, pathP, pathQ, curr);
        
        curr.pop_back();        // Backtracking
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ, curr;
        
        traverse(root, p, q, pathP, pathQ, curr);
        
        TreeNode* ans = NULL;
        for(int i = 0; i < min(pathP.size(), pathQ.size()); ++i) {
            if(pathP[i] == pathQ[i])    // This is lowest common ancestor till now
                ans = pathP[i];
            else                        // Paths aren't same, so BREAK
                break;
        }
        
        return ans;
    }
};





///////////////////////
///   Solution 2   ///
/////////////////////

// Time Complexity - O(n)
// Space Complexity - O(n), n => call stack

class Solution {
public:
    TreeNode* traverse(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans) {
        if(!root)       return NULL;
        
        TreeNode* left  = traverse(root->left,  p, q, ans);
        TreeNode* right = traverse(root->right, p, q, ans);
        
        // If both P and Q are found, assign 'ans'
        if(
            (left == p  &&  right == q) || (left == q  &&  right == p) ||
            (left == p  &&  root  == q) || (left == q  &&  root  == p) ||
            (right == p  &&  root == q) || (right == q  &&  root == p)
         ) {
            ans = root;
        }
        
        if(left == p  ||  left == q)        // If 'left' is P or Q, then return it
            return left;                    // instead of root
        
        if(right == p  ||  right == q)      // If 'right' is P or Q, then return it
            return right;                   // instead of root
        
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ, curr;
        TreeNode* ans;
        
        traverse(root, p, q, ans);
        
        return ans;
    }
};