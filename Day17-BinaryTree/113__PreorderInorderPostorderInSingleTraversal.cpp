// Time Complexity - O(n)
// Space Complexity - O(n)

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans;
    
    // No nodes in tree
    if(!root)	return ans;
    
    vector<int> inorder, preorder, postorder;
    
    stack<pair<BinaryTreeNode<int>*, int>> st;
    st.push({root, 1});               // Push 'root' node
    
    while(!st.empty()) {
        BinaryTreeNode<int>* node = st.top().first;
        int num = st.top().second;
        st.pop();
        
        if(num == 1) {                                  // num==1, we put into preorder
            preorder.push_back(node->data);
            st.push({node, num+1});                     // increment its num and push again
            if(node->left)	st.push({node->left, 1});
        }
        else if(num == 2) {
            inorder.push_back(node->data);              // num==2, we put into preorder
            st.push({node, num+1});                     // increment its num and push again
            if(node->right)	st.push({node->right, 1});  
        }
        else if(num == 3) {                             // num==2, we put into preorder
            postorder.push_back(node->data);            // no list to be put in, thus no insertion
        }
    }
    
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    
    return ans;
}