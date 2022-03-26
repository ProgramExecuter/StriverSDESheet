bool path(TreeNode* root, int ele, vector<int>& ans) {
    if(!root)   return false;   // NULL sub-tree
    
    ans.push_back(root->val);

    if(root->val == ele)    return true;  // Req. node found

    // If the required node is present in right, return TRUE
    bool left = path(root->left, ele, ans);
    if(left)    return true;

    // If the required node is present in right, return TRUE
    bool right = path(root->right, ele, ans);
    if(right)   return true;
    
    ans.pop_back();     // Backtrack
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;

    path(A, B, ans);

    return ans;
}