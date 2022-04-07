// Time Complexity - O(N)
// Space Complexity - O(N), for call stack

class Solution {
public:
    bool check(int curr, vector<vector<int>>& graph, vector<int> &flag, int par) {
        if(par == -1)
            flag[curr] = 0;
        else
            flag[curr] = 1-flag[par];           // Put different color than parent
        
        for(int ele : graph[curr]) {
            if(ele == par)  continue;

            if(flag[ele] == -1) {               // First time visited
                if(!check(ele, graph, flag, curr))
                    return false;
            }
            else if(flag[ele] != flag[curr]) {   // Has been visited, but not same color
                ;
            }
            else {                              // Visited, same color
                return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> flag(n, -1);
        
        for(int i = 0; i < n; ++i) {
            if(flag[i] != -1)   continue;   // Already visited
            
            // If this isn't bipartite graph, return FALSE
            if(!check(i, graph, flag, -1))       
                return false;
        }
        
        return true;
    }
};