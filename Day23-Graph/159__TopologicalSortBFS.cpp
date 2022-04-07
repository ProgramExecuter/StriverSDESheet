// Time Complexity - O(N)
// Space Complexity - O(N + N + N), for queue, 'inD' and 'ans'

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    vector<int> ans, inD(n, 0);
	    queue<int> q;
	    
	    // Calculate in-degree of each node
	    for(int i = 0; i < n; ++i) {
	        for(int neigh : adj[i])
	            ++inD[neigh];
	    }
	    
	    for(int i = 0; i < n; ++i) {
	        if(inD[i] == 0)     q.push(i);
	    }
	    
	    while(!q.empty()) {
	        int curr = q.front();
	        q.pop();
	        
	        for(int ele : adj[curr]) {
	            --inD[ele];
	            
	            if(inD[ele] == 0)
	                q.push(ele);
	        }
	        
	        ans.push_back(curr);
	    }
	    
	    return ans;
	}
};