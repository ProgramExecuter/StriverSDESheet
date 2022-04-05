// Time Complexity - O(N)
// Space Complexity - O(N)

//**
//  SKELETON OF "ADJ"
//  adj  => [
//              0: [1,2,6],
//              1: [3,5],
//              2: [],
//              .........
//            v-1: [6],
//          ]
//**

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        vector<int> ans, vis(v, 0);
        
        queue<int> q;
        
        for(int i=0; i<v; ++i) {
            if(vis[i] == 1)         // This vertex is visited, skip it
                continue;
            
            q.push(i);
            vis[i] = 1;
            
            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                
                ans.push_back(curr);
                
                for(int tmp : adj[curr]) {    // Neighbors of the 'curr'
                    if(vis[tmp] == 0) {
                        q.push(tmp);
                        vis[tmp] = 1;
                    }
                }
            }
        }
        
        return ans;
    }
};