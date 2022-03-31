// Time Complexity - O(n)
// Space Complexity - O(n), for call stack

class Solution {
public:
    pair<vector<int>, bool> util(TreeNode* root, int &ans) {
        pair<vector<int>, bool> l, r;
        
        int sum = root->val, low = root->val, high = root->val;
        bool isBST = true;
        
        if(root->left) {
            l = util(root->left,  ans);
            
            if( (!l.second) ||                      // If the left-subtre isn't BST 
                (l.first[2] >= root->val) ) {       // If left's max value >= this node's value
                isBST = false;
            }
            
            sum += l.first[0];
            low  = min(low,  min(l.first[1], l.first[2]));
            high = max(high, max(l.first[1], l.first[2]));
        }
            
        if(root->right) {
            r = util(root->right,  ans);
            
            if( (!r.second) ||                      // If the right-subtre isn't BST 
                (r.first[1] <= root->val) ) {       // If right's min value <= this node's value
                isBST = false;
            }
            
            sum += r.first[0];
            low  = min(low,  min(r.first[1], r.first[2]));
            high = max(high, max(r.first[1], r.first[2]));
        }
        
        if(isBST)   ans = max(ans, sum);
        
        return {{sum, low, high}, isBST};
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        
        util(root, ans);
        
        return ans;
    }
};