// Time Complexity - O(n)
// Space Complexity - O(n)

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