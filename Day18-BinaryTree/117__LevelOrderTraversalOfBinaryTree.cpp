// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        // No nodes in tree
        if(!root)   return ans;
        
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        
        int prevLevel = -1;
        while(!q.empty()) {
            int level =  q.front().first;
            TreeNode* node = q.front().second;
            q.pop();
            
            // If this is new level, then add new array for this new level
            if(prevLevel != level) {
                vector<int> tmp;
                ans.push_back(tmp);
            }
            
            ans[level].push_back(node->val);                    // Push value to answer
            
            if(node->left)  q.push({level+1, node->left});      // Push left node to stack
            if(node->right) q.push({level+1, node->right});     // Push right node to stack
            
            prevLevel = level;
        }
        
        return ans;
    }
};