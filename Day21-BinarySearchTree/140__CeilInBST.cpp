// Time Complexity - O(logn), O(n) => worst case(skew tree)
// Space Complexity - O(1)

int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = -1;
    BinaryTreeNode<int>* tmp = node;
    
    while(tmp) {
        if(tmp->data >= x) {
            ans = tmp->data;        // This can be the result
            tmp = tmp->left;        // Check left-subtree
        }
        else {
            tmp = tmp->right;       // Check right-subtree
        }
    }
    
    return ans;
}