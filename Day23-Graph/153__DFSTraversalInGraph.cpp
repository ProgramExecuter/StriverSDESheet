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
    void dfs(int curr, int &v, vector<int> adj[], vector<int> &ans, vector<int> &vis) {
        ans.push_back(curr);    // Push it to "ans"
        vis[curr] = 1;
        
        for(int i : adj[curr]) {    // Visit neighbours of "curr"
            if(vis[i] == 1)
                continue;
            
            dfs(i, v, adj, ans, vis);   // Visit in-depth
        }
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int> ans, vis(v, 0);
        
        for(int i=0; i<v; ++i) {
            if(vis[i] == 1)     continue;       // Skip, already visited
            
            dfs(i, v, adj, ans, vis);
        }
        
        return ans;
    }
};