///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(n)
// Space Complexity - O(n), for call stack

// **This solution has problem when it's range is [INT_MIN, INT_MAX] and only 'int' type is allowed

class Solution {
public:
    bool check(TreeNode* root, long lb, long ub) {
        if(!root)   return true;
        
        if(root->val <= lb)  return false;
        if(root->val >= ub)  return false;
        
        bool left  = check(root->left, lb, root->val);
        bool right = check(root->right, root->val, ub);
        
        return (left && right);
    }
    bool isValidBST(TreeNode* root) {
        long lb = LONG_MIN, ub = LONG_MAX;
        return check(root, lb, ub);
    }
};





///////////////////////
///   Solution 2   ///
/////////////////////

// Time Complexity - O(n)
// Space Complexity - O(n), for call stack

class Solution {
public:
    bool check(TreeNode* root, TreeNode* lb, TreeNode* ub) {
        if(!root)   return true;
                
        if(lb && ub) {      // If both sides are bounded
            if(root->val <= lb->val  ||  root->val >= ub->val)  return false;
        }
        else if(lb) {       // If only left side is bounded
            if(root->val <= lb->val)    return false;
        }
        else if(ub) {       // If only right side is bounded
            if(root->val >= ub->val)    return false;
        }
        
        bool left = check(root->left, lb, root);
        bool right = check(root->right, root, ub);
        
        return (left && right);
    }
    bool isValidBST(TreeNode* root) {
        return check(root, NULL, NULL);
    }
};