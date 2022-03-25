// Time Complexity - O(n)
// Space Complexity - O(logn)  => since logn would be width of a regular binary tree 

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int, int> vis;
        
        if(!root)   return ans;
        
        queue<pair<Node*, int>> st;
        st.push({root, 0});
        
        while(!st.empty()) {
            Node* curr = st.front().first;
            int level = st.front().second;
            st.pop();
            
            vis[level] = curr->data;        // Mapping this level to data
            
            if(curr->left)   st.push({curr->left,  level-1});
            if(curr->right)  st.push({curr->right, level+1});
        }
        
        for(auto i : vis)
            ans.push_back(i.second);
        
        return ans;
    }
};