// Time Complexity - O(N)
// Space Complexity - O(4*N), for call stack, 'vis', 'ans' and stack

class Solution
{
	public:
	void dfs(int curr, vector<int> adj[], stack<int> &st, vector<bool> &vis) {
	    vis[curr] = true;                 // Mark this as visited
	    
	    for(int neigh : adj[curr]) {
	        if(vis[neigh])  continue;     // Skip visited
	        
	        dfs(neigh, adj, st, vis);
	    }
	    
	    st.push(curr);                    // Push to stack
	}
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    stack<int> st;
	    vector<int> ans;
	    vector<bool> vis(n, false);
	    
	    for(int i = 0; i < n; ++i) {
	        if(vis[i]) continue;
	        
	        dfs(i, adj, st, vis);
	    }
	    
	    while(!st.empty()) {
	        ans.push_back( st.top() );
	        st.pop();
	    }
	    
	    return ans;
	}
};