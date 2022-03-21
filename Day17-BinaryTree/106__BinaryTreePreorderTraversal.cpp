////////////////////////
///   Solution 1   ////
//////////////////////

// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(!root)   return ans;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            
            ans.push_back(node->val);               // Push it value to 'result'
            if(node->right) st.push(node->right);   // Push 'right' to stack
            if(node->left)  st.push(node->left);    // Push 'left' to stack
        }
        
        return ans;
    }
};