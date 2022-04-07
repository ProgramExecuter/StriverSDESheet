// Time Complexity - O(N)
// Space Complexity - O(N + 2*N), for call stack, 'vis', 'dfsVis'

class Solution {
  public:
    bool hasCycle(int curr, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis) {
        vis[curr] = true;
        dfsVis[curr] = true;
        
        // Neighbour of 'curr'
        for(int ele : adj[curr]) {
            if(dfsVis[ele])    return true;     // Already visited in this DFS, cycle
            
            if(!vis[ele]) {                     // Check only if it hasn't been visited
                if(hasCycle(ele, adj, vis, dfsVis))
                    return true;
            }
        }
        
        dfsVis[curr] = false;                   // Backtrack
        
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<bool> dfsVis(V, false);
        
        for(int i = 0; i < V; ++i) {
            if(vis[i])  continue;   // Skip visited components
            
            if( hasCycle(i, adj, vis, dfsVis) ) {
                return true;
            }
        }
        return false;
    }
};