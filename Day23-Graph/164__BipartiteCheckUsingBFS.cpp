// Time Complexity - O(N)
// Space Complexity - O(N), for queue

class Solution {
public:
    bool check(int curr, vector<vector<int>>& graph, vector<int> &flag) {
        queue<pair<int, int>> q;
        q.push({curr, -1});         // No parent
        flag[curr] = 0;
        
        while(!q.empty()) {
            int tmp = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for(int ele : graph[tmp]) {
                if(ele == par)  continue;
                
                if(flag[ele] == -1) {               // First time visited
                    flag[ele] = 1-flag[tmp];
                    q.push({ele, tmp});
                }
                else if(flag[ele] != flag[tmp]) {   // Has been visited, but not same color
                    ;
                }
                else {                              // Visited, same color
                    return false;
                }
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> flag(n, -1);
        
        for(int i = 0; i < n; ++i) {
            if(flag[i] != -1)   continue;   // Already visited
            
            if(!check(i, graph, flag)) {                  // If this isn't bipartite graph, return FALSE
                return false;
            }
        }
        
        return true;
    }
};