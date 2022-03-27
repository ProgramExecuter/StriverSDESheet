// Time Complexity - O(n)
// Space Complexity - O(n), n => call stack

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p  &&  !q)  return true;
        if(p  &&  !q)   return false;
        if(q  &&  !p)   return false;
        
        if(p->val != q->val)      return false;     // If root values are same
        
        bool left  = isSameTree(p->left,  q->left);
        bool right = isSameTree(p->right, q->right);
        
        return (left && right);         // If left and right sub-tree are same
    }
};