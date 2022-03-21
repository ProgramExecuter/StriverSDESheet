///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(!root)   return ans;
        
        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});
        
        while(!st.empty()) {
            // Push the already visited node's value in result
            while(!st.empty()  &&  st.top().second) {
                ans.push_back(st.top().first->val);
                st.pop();
            }
            
            if(st.empty())  break;
            
            TreeNode* node = st.top().first;
            st.pop();
            
            st.push({node, true});                          // Push this node
            if(node->right) st.push({node->right, false});  // Push right
            if(node->left)  st.push({node->left, false});   // Push left
        }
        
        return ans;
    }
};