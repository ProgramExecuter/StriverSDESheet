// Time Complexity - O(1) => hasNext
//                 ~ O(1) => next,     almost O(1)
// Space Complexity - O(H), H = height of BST

class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        TreeNode* tmp = root;
        while(tmp) {
            st.push(tmp);
            tmp = tmp->left;      // Put all left nodes in stack
        }
    }
    
    int next() {
        if(!hasNext())  return -1;
        
        TreeNode* tmp = st.top();
        int res = tmp->val;
        st.pop();
        
        tmp = tmp->right;       // Put right-node and all its left nodes
        while(tmp) {
            st.push(tmp);
            tmp = tmp->left;
        }
        
        return res;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
