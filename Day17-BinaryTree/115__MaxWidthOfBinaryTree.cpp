class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        
        long long ans = 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            int n = q.size();
            long long del = q.front().second;
            
            long long low, high;
            for(int i=0; i<n; ++i) {
                long long num = q.front().second - del;   // To start 'num' from 0
                TreeNode* node = q.front().first;
                q.pop();
                
                if(i == 0)      low  = num;
                if(i == n-1)    high = num;
                
                if(node->left)
                    q.push({node->left,  (num*2)+1});
                if(node->right)
                    q.push({node->right, (num*2)+2});
            }
            
            ans = max(ans, high-low+1);
        }
        
        return int(ans);
    }
};