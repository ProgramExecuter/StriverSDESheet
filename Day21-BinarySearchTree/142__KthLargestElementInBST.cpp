///////////
// For first solution, we can store inorder traversal, and print k-th smallest from sorted array
// But, Space Complexiy becomes O(n + n), n => for array, stack space
///////////





// Time Complexity - O(logn), O(n) => worst case(skew tree)
// Space Complexity - O(n), stack space

class Solution
{
    public:
    void util(Node *root, int &k, int &ans) {
        if(!root)   return;
        
        util(root->right, k, ans);
        
        if(--k == 0)    ans = root->data;
        
        util(root->left, k, ans);
    }
    int kthLargest(Node *root, int K)
    {
        int ans;
        util(root, K, ans);
        return ans;
    }
};