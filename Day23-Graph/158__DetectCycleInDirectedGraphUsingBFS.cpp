// Time Complexity - O(N)
// Space Complexity - O(N + N), for 'inD' and queue


class Solution {
  public:
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int>  inD(n, 0);
        
        // Calculate indegree of all nodes of graph
        for(int i = 0; i < n; ++i) {
            for(int neigh : adj[i])
                ++inD[neigh];
        }
        
        int cntEleTopo = 0;
        queue<int> q;
        
        // Push nodes with 0 in-degree
        for(int i=0; i<n; ++i) {
            if(inD[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int tmp = q.front();
            q.pop();
            
            for(int ele : adj[tmp]) {
                --inD[ele];
                
                if(inD[ele] == 0)       // If in-degree becomes push it to queue
                    q.push(ele);
            }
            
            ++cntEleTopo;
        }
        
        if(cntEleTopo == n)         // Topological sort can be done, thus no cycle
            return false;
        
        return true;
    }
};