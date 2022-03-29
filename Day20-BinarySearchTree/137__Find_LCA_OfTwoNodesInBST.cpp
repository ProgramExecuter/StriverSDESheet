///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(2*logn), two time searching
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
// Space Complexity - O(n), call stack

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)       return NULL;
        
        int curr = root->val;
        
        if(curr < p->val  &&  curr < q->val) {    // Check the nodes in right-BST
            return lowestCommonAncestor(root->right, p, q);
        }
        if(curr > p->val  &&  curr > q->val) {    // Check the nodes in left-BST
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // Here the nodes's path split, thus this is LCA
        cout << root->val << endl;
        return root;
    }
};