///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(n + n), two time searching
// Space Complexity - O(n+n), call stack + hash-set

class Solution {
public:
    vector<TreeNode*> findNode(TreeNode* root, TreeNode* req) {
        TreeNode* tmp = root;
        vector<TreeNode*> ans;
        
        while(tmp) {
            ans.push_back(tmp);
            if(tmp == req)                  // Found the required NODE
                break;
            else if(tmp->val < req->val)    // Search in right-subtree
                tmp = tmp->right;
            else                            // Search in left-subtree
                tmp = tmp->left;
        }
        
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        set<TreeNode*> st;
        
        pathP = findNode(root, p);
        pathQ = findNode(root, q);
        
        for(auto tmp : pathP)
            st.insert(tmp);
        
        reverse(pathQ.begin(), pathQ.end());        // We want lowest common ancestor
        
        for(auto tmp : pathQ) {
            if(st.find(tmp) != st.end())    return tmp;     // Found LCA
        }
        
        return NULL;
    }
};





///////////////////////
///   Solution 2   ///
/////////////////////

// Time Complexity - O(n)
// Space Complexity - O(n), call stack + hash-set

class Solution {
public:
    TreeNode* findNode(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans) {
        if(!root)   return NULL;
        
        TreeNode* left  = findNode(root->left, p, q, ans);
        TreeNode* right = findNode(root->right, p, q, ans);
        
        // Found a LCA
        if( ans == NULL &&
            (left==p && right==q) || (left==q && right==p) ||
            (root==p &&  left==q) || (root==q &&  left==p) ||
            (root==p && right==q) || (root==q && right==p) )
        {
          ans = root;
        }
        
        if(left  == p  ||  left  == q)      return left;    // Found any one, RETURN
        if(right == p  ||  right == q)      return right;
        if(root  == p  ||  root  == q)      return root;
        
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        
        findNode(root, p, q, ans);
        
        return ans;
    }
};