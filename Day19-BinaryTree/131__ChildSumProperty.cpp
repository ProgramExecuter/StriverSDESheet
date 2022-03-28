// Time Complexity - O(n)
// Space Complexity - O(n), call Stack

int solve(BinaryTreeNode<int>* root, int par) {
    if(!root)	return 0;
    
    if(root->data < par)    // If this node < parent, then make it = par
        root->data = par;
	
    // Leaf Node, RETURN data
    if(!root->left  &&  !root->right)
        return root->data;
    
    int l = solve(root->left, root->data);    // Values of left & right nodes
    int r = solve(root->right, root->data);
    
    root->data = l+r;   // Make this node as sum of left and right node's sum
    
    return root->data;
}
void changeTree(BinaryTreeNode<int>* root) {
    if(!root)	return;
    if(!root->left  &&  !root->right)	return;
    
    int l = solve(root->left, root->data);
    int r = solve(root->right, root->data);
    
    root->data = l + r;
}