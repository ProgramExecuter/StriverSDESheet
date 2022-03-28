void traverseLeft(TreeNode<int>* root, vector<TreeNode<int>*> &left) {
    while(root  &&  (root->left  ||  root->right)) {
        left.push_back(root);
        if(root->left)	root = root->left;
      	else			root = root->right;
    }
}
void traverseRight(TreeNode<int>* root, vector<TreeNode<int>*> &right) {
    while(root  &&  (root->left  ||  root->right)) {
        right.push_back(root);
        if(root->right)	root = root->right;
    	  else			root = root->left;
    }
}
void traverseBottom(TreeNode<int>* root, vector<TreeNode<int>*> &bottom) {
    if(!root)	return;
    
    if(!root->left  &&  !root->right)
        bottom.push_back(root);
    
    traverseBottom(root->left,  bottom);
    traverseBottom(root->right, bottom);
}
vector<int> traverseBoundary(TreeNode<int>* root) {
    vector<TreeNode<int>*> left, right, bottom;
    vector<int> ans;

    if(!root)	return ans;     // No nodes, RETURN
    
    ans.push_back(root->data);
    
    if(!root->left && !root->right)		return ans;   // Only 1 node, push and return
    
    traverseLeft(root->left, left);
    traverseRight(root->right, right);
    traverseBottom(root, bottom);
    
    // Put left boundary elements
    for(auto i : left)      ans.push_back(i->data);
    
    // Put leaf nodes
    for(auto i : bottom)    ans.push_back(i->data);
    
    // Put right boundary elements in reverse order
    reverse(right.begin(), right.end());
    for(auto i : right)     ans.push_back(i->data);
    
    return ans;
}