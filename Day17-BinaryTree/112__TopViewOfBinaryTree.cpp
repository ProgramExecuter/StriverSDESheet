// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(!root)   return ans;
        
        map<int, int> mp;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            Node* node = q.front().first;
            int x = q.front().second;
            q.pop();
            
            if(mp.find(x) == mp.end())      // If this x-level isn't filled
                mp[x] = node->data;          // then insert this value
                
            if(node->left)      q.push({node->left,  x-1});
            if(node->right)     q.push({node->right, x+1});
        }
        
        for(auto i : mp)
            ans.push_back(i.second);
        
        return ans;
    }
};