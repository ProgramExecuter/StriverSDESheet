// Time Complexity - O(2*logn)
// Space Complexity - O(n), calls stack

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if(!root) return;
    
    // successor
    Node* curr = root;
    while(curr) {
        if(curr->key > key){
            suc  = curr;        // Can be 'suc'
            curr = curr->left;
        }
        else
            curr = curr->right;
    }
    
    // predecessor
    curr = root;
    while(curr) {
        if(curr->key < key) {
            pre  = curr;          // Can be 'pre'
            curr = curr->right;
        }
        else
            curr = curr->left;
    }
}