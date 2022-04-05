// Time Complexity - O(N)
// Space Complexity - O(N + N)  ==>  'vis' array  +  call stack

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
    bool hasCycle(int curr, int par, vector<bool>& vis, vector<int> adj[]) {
        vis[curr] = true;

        // Neighbours of 'curr'
        for(int ele : adj[curr]) {
            if(ele == par)    continue;         // Parent, SKIP
            
            if(vis[ele])                        // Neighbour already visited, not parent
                return true;                    // Thus a cycle
            
            if(hasCycle(ele, curr, vis, adj))
                return true;
        }
        
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        vector<bool> vis(v, 0);
        
        for(int i=0; i<v; ++i) {
            if(vis[i])  continue;                       // Already visited, SKIP
            
            if(hasCycle(i, -1, vis, adj))               // Has a cycle
                return true;
        }
        
        return false;
    }
};