///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        
        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});
        
        while(!st.empty())
        {            
            // push all the visited nodes to result
            while(!st.empty()  &&  st.top().second) {
                ans.push_back(st.top().first->val);
                st.pop();
            }
            
            if(st.empty())  break;
            
            TreeNode* node = st.top().first;
            st.pop();
            
            if(node->right)  st.push({node->right, false});     // Push right node
            st.push({node, true});                              // Push parent node
            if(node->left)  st.push({node->left, false});       // Push left node
        }
        
        return ans;
    }
};