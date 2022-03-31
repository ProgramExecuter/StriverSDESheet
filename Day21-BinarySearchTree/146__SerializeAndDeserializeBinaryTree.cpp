class Codec {
public:
    // Encodes a tree to a single string.
    int getNum(string &data, int &i) {
        int num = 0, sign = 1;
        
        if(data[i] == '-') {        // -ve number
            sign = -1;
            ++i;
        }
        
        while(data[i] != ',') {             // Get the number
            num = num*10 + (data[i]-48);
            ++i;
        }
        ++i;                                // Skip "," after number
        
        return num*sign;
    }
    string serialize(TreeNode* root) {
        if(!root)   return "";
        
        string ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr == NULL) {
                ans += "N,";
                continue;
            }
            
            ans += to_string(curr->val) + ",";        // Add value to string
            
            q.push(curr->left);
            q.push(curr->right);
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)    return NULL;
        
        int i = 0;
        
        int num = getNum(data, i);                  // Get value of this node
        TreeNode* root = new TreeNode(num);         // Create this node
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            
            // Find its left node
            if(data[i] == 'N') {    // Left node is NULL
                i += 2;
                tmp->left = NULL;
            }
            else {
                int num = getNum(data, i);        // Left node's value 
                TreeNode *l = new TreeNode(num);  // Left Node         
                tmp->left = l;                    // Attaching Left Node
                
                q.push(l);
            }
            
            // Find its right
            if(data[i] == 'N') {    // Right node is NULL
                i += 2;
                tmp->right = NULL;
            }
            else {
                int num = getNum(data, i);        // Right node's value
                TreeNode *r = new TreeNode(num);  // Right Node
                tmp->right = r;                   // Attaching Right Node
                
                q.push(r);
            }
        }
        
        return root;
    }
};