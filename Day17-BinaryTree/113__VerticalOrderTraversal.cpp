// Time Complexity - O(nlogn)
// Space Coplexity - O(n)

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root)   return ans;         // No nodes, RETURN
        
        map<int, map<int, multiset<int>>> mp;   // map( x-axis, map( vertical_level, nums ) )
        
        queue<pair<TreeNode*, int>> q;  // Stores node and its x(x-axis distance)
        q.push({root, 0});
        
        int level = 0;                  // Intial vertical level = 0
        while(1) {
            int n = q.size();
            
            if(n == 0)      break;      // Break when queue becomes empty
            
            while(n--) {
                TreeNode* node = q.front().first;
                int x = q.front().second;
                q.pop();
                
                mp[x][level].insert(node->val);     // Insert this value to build 'ans'
                
                if(node->left)      q.push({node->left,  x-1});
                if(node->right)     q.push({node->right, x+1});
            }
            
            ++level;        // Increment vertical level
        }
        
        for(auto x : mp) {
            vector<int> tmp;
            
            // For each x-axis
            for(auto level : x.second) {
                // For each level, insert sorted elements
                for(int ele : level.second) {
                    tmp.push_back(ele);
                }
            }
            
            ans.push_back(tmp);
        }

        return ans;
    }
};