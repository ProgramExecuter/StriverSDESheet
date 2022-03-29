// Time Complexity - O(n)
// Space Complexity - O(n), call stack

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)   return NULL;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int len = q.size();
            Node* nxt = NULL;
            
            while(len--) {
                Node* curr = q.front();
                q.pop();
                
                if(curr->right)     q.push(curr->right);
                if(curr->left)      q.push(curr->left);
                
                curr->next = nxt;       // Make inorder-previous node as 'next'
                nxt = curr;             // Make this 'nxt' for next node
            }
        }
        
        return root;
    }
};