///////////////////////
///   Solution 1   ///
/////////////////////

// Take each node, let's say with value 'X', then find the node with value 'k-X'
// Taking each node (N), finding its pair log(N)

// Time Complexity - O(NlogN)
// Space Complexity - O(1)






///////////////////////
///   Solution 2   ///
/////////////////////

// Store inorder traversal, and then problem becomes '2 Sum in sorted array'

// Time Complexity - O(N)
// Space Complexity - O(N)






///////////////////////
///   Solution 3   ///
/////////////////////

// Time Complexity - O(N)
// Space Complexity - O(H), H => height of BST

// Check  Q.No 143 first

class BSTIteratorNext {
public:
    stack<TreeNode*> st;
    BSTIteratorNext(TreeNode* root) {
        TreeNode* tmp = root;
        
        while(tmp) {
            st.push(tmp);
            tmp = tmp->left;
        }
    }
    
    int next() {
        if(st.empty())  return -1;
        
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

class BSTIteratorPrev {
public:
    stack<TreeNode*> st;
    BSTIteratorPrev(TreeNode* root) {
        TreeNode* tmp = root;
        
        while(tmp) {
            st.push(tmp);
            tmp = tmp->right;
        }
    }
    
    int prev() {
        if(st.empty())  return -1;
        
        TreeNode* tmp = st.top();
        int res = tmp->val;
        st.pop();
        
        tmp = tmp->left;       // Put right-node and all its left nodes
        while(tmp) {
            st.push(tmp);
            tmp = tmp->right;
        }
        
        return res;
    }
    
    bool hasPrev() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)   return false;
        
        BSTIteratorNext *nxt = new BSTIteratorNext(root);
        BSTIteratorPrev *pre = new BSTIteratorPrev(root);
        

        // 2 SUM
        int low  = nxt->next();
        int high = pre->prev();
        while(low < high) {
            if(low+high == k) {
                return true;
            }
            else if(low+high < k) {
                if(nxt->hasNext())  low = nxt->next();
                else                return false;
            }
            else {
                if(pre->hasPrev())  high = pre->prev();
                else                return false;
            }
        }
        
        return false;
    }
};