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
    bool hasCycle(int st, vector<bool>& vis, vector<vector<int>> &adj) {
        queue<pair<int, int>> q;
        q.push({st, -1});
        vis[st] = true;
        
        while(!q.empty()) {
            int curr = q.front().first;         // Get front of QUEUE
            int par  = q.back().second;         // Get 'parent'
            q.pop();
            
            // Neighbours of 'curr'
            for(int ele : adj[curr]) {
                if(ele == par)    continue;         // Parent, SKIP
                
                if(vis[ele])                        // Neighbour already visited, not parent
                    return true;                    // Thus a cycle
                
                q.push({ele, curr});
                vis[ele] = true;
            }
        }
        
        return false;
    }
    bool canFinish(int v, vector<vector<int>>& adj) {
        vector<bool> vis(v, 0);
        
        vector<vector<int>> adj = convert(adj, v);  // Convert to adjancency mat, for graph
        
        for(int i=0; i<v; ++i) {
            if(vis[i])  continue;                   // Already visited, SKIP
            
            if(hasCycle(i, vis, adj))               // Has a cycle
                return false;
        }
        
        return true;
    }
};