// Time Complexity - O(n)
// Space Complexity - O(n), call stack

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(!node)   return;     // Node == NULL
        
        Node* left = node->left;
        Node* right = node->right;
        
        node->left  = right;    // Mirroring left and right
        node->right = left;
        
        mirror(node->left);
        mirror(node->right);
    }
};